using System;
using System.IO;
using System.Net.NetworkInformation;
using System.Security.Cryptography;
using System.Text;
using System.Diagnostics;
using System.Runtime.InteropServices;

namespace Common.WM
{
    #region COM Stuff

    // Create a class factory to manage passing the singleton
    // instance to a COM client

    [ComVisible(true)]
    [Guid("17985A46-13C5-4797-8FC0-73DB607B3B02")]
    public interface IConnectFactory
    {
        IConnect Create();
    }

    [ComVisible(true)]
    [ClassInterface(ClassInterfaceType.None)]
    [Guid("30C23B6C-66FF-4CA5-A0D9-885FB73FBEBB")]
    public class ConnectFactory : IConnectFactory
    {
        public IConnect Create() { return ConnectConfig.Instance; }
    }

    [ComVisible(true)]
    [Guid("82B98E45-22E5-498F-98E1-12D9E9BA74F1")]
    public interface IConnect
    {
        bool IsEnabled { get; }
        bool IsConnected { get; }
        bool IsInternetConnected { get; }

        event EventHandler StatusChanged;

        // Passing delegates over COM-Interop does not work well for Reg-free COM
        // because delegate types end up with an implicit interface that must be registered.
        //
        // The alternative is to just pass the function pointer, while not ideal (not type-safe),
        // it alleviates the need for registering the implicit delegate interface.

        void AddStatusDelegate(IntPtr funcPtr);
    }

    #endregion

    [Flags]
    public enum ConnectStatus : uint
    {
        None                    = 0x00,
        Busy                    = 0x01,
        Enabled                 = 0x02,
        Connected               = 0x04,
        NoInternetConnection    = 0x08,
        ProxyError              = 0x10,
        Registering             = 0x20,
        StartSession            = 0x40,
        RemoteUserName          = 0x80,
    }

    internal class ConnectConfig : IConnect
    {
        private const string ACK_FILE   = @"C:\SJM\SJMConnect\cfg\SJMCONNECT_ACK";
        private const string PROXY_FILE = @"C:\SJM\SJMConnect\cfg\SJMCProxy.cfg";
        private const string START_EXE  = @"C:\SJM\SJMConnect\Bin\startconnect.exe";
        private const string STOP_EXE   = @"C:\SJM\SJMConnect\Bin\stopconnect.exe";

        #region IConnect

        public bool IsEnabled { get { return (_status & ConnectStatus.Enabled) != 0; } }

        public bool IsConnected { get { return (_status & ConnectStatus.Connected) != 0; } }

        public bool IsInternetConnected { get { return (_status & ConnectStatus.NoInternetConnection) == 0; } }

        public event EventHandler StatusChanged;

        public void AddStatusDelegate(IntPtr funcPtr)
        {
            EventHandler del = Marshal.GetDelegateForFunctionPointer(funcPtr, typeof(EventHandler)) as EventHandler;
            StatusChanged += del;
        }

        #endregion

        #region Properties

        private ConnectStatus _status = ConnectStatus.None;
        public ConnectStatus Status
        {
            get { return _status; }
            private set
            {
                if (_status != value)
                {
                    _status = value;
                    InvokeEvent(StatusChanged);
                }
            }
        }

        public bool IsBusy      { get { return (_status & ConnectStatus.Busy) != 0; } }
        public bool NoInternet  { get { return (_status & ConnectStatus.NoInternetConnection) != 0; } }
        public bool ProxyError  { get { return (_status & ConnectStatus.ProxyError) != 0; } }
        
        public bool HasErrors
        {
            get
            {
                var mask = ConnectStatus.NoInternetConnection | ConnectStatus.ProxyError;
                return (_status & mask) != 0;
            }
        }

        private string _proxyUser;
        public string ProxyUsername
        {
            get { return _proxyUser; }
            private set
            {
                if (_proxyUser != value)
                {
                    _proxyUser = value;
                }
            }
        }
        
        private string _proxyPwd;
        public string ProxyPassword
        {
            get { return _proxyPwd; }
            private set
            {
                if (_proxyPwd != value)
                {
                    _proxyPwd = value;
                }
            }
        }

        private string _host;
        public string Host
        {
            get { return _host; }
            private set
            {
                if (_host != value)
                {
                    _host = value;
                }
            }
        }

        private int _port;
        public int Port
        {
            get { return _port; }
            private set
            {
                if (_port != value)
                {
                    _port = value;
                }
            }
        }

        #endregion

        private FileSystemWatcher _ackWatcher;
        private FileSystemWatcher _proxyWatcher;

        private ConnectConfig()
        {
            if (File.Exists(ACK_FILE))
            {
                ReadACKFile();

                _ackWatcher = new FileSystemWatcher();
                _ackWatcher.Path = Path.GetDirectoryName(ACK_FILE);
                _ackWatcher.Filter = Path.GetFileName(ACK_FILE);
                _ackWatcher.NotifyFilter = NotifyFilters.LastWrite;
                _ackWatcher.IncludeSubdirectories = false;
                _ackWatcher.EnableRaisingEvents = true;

                _ackWatcher.Changed += OnACKFileChanged;
            }

            if (File.Exists(PROXY_FILE))
            {
                ReadProxyFile();

                _proxyWatcher = new FileSystemWatcher();
                _proxyWatcher.Path = Path.GetDirectoryName(PROXY_FILE);
                _proxyWatcher.Filter = Path.GetFileName(PROXY_FILE);
                _proxyWatcher.NotifyFilter = NotifyFilters.LastWrite;
                _proxyWatcher.IncludeSubdirectories = false;
                _proxyWatcher.EnableRaisingEvents = true;

                _proxyWatcher.Changed += OnProxyFileChanged;
            }
        }

        private void InvokeEvent(EventHandler evt)
        {
            try
            {
                if (evt != null)
                    evt(this, null);
            }
            catch (Exception ex)
            {
                System.Diagnostics.Debug.WriteLine("Error in Common.WM.Net InvokeEvent: " + ex.Message);
            }
        }

        public bool Start()
        {
            return RunEXE(START_EXE);
        }

        public bool Stop()
        {
            return RunEXE(STOP_EXE);
        }

        private Process _curProcess;

        private bool RunEXE(string filename)
        {
            if(_curProcess!=null) return false;
            if(!File.Exists(filename)) return false;

            var p = new Process
            {
                StartInfo =
                {
                    FileName = filename,
                    CreateNoWindow = true,
                    UseShellExecute = false
                },
                EnableRaisingEvents = true
            };

            p.StartInfo.Arguments = "";
            p.Exited += OnProcessExited;
            
            lock(this)
            {
                _curProcess = p;
                _curProcess.Start();
            }

            return true;
        }

        private void OnProcessExited(object sender, EventArgs e)
        {
            lock (this)
            {
                _curProcess.Dispose();
                _curProcess = null;
            }
        }

        #region ACK File

        private void OnACKFileChanged(object sender, FileSystemEventArgs e)
        {
            ReadACKFile();
        }

        private bool ReadACKFile()
        {
            try
            {
                var temp = Common.INIFile.ReadValue(ACK_FILE, "SJMConnect", "Status");
                int val = 0;
                if (int.TryParse(temp, out val))
                    Status = (ConnectStatus)val;
                else
                    Status = ConnectStatus.None;

                return true;
            }
            catch (Exception ex)
            {
                System.Diagnostics.Debug.WriteLine("Error in Common.WM.Net ReadACKFile: " + ex.Message);
                return false;
            }
        }

        #endregion

        #region PROXY File

        private void OnProxyFileChanged(object sender, FileSystemEventArgs e)
        {
            ReadProxyFile();
        }

        private bool ReadProxyFile()
        {
            try
            {
                var temp = Common.INIFile.ReadValue(PROXY_FILE, "Proxy", "server");

                string host = temp;
                int port = 0;
                if (!string.IsNullOrEmpty(temp))
                {                   
                    int start = temp.LastIndexOf(':') + 1;
                    if (start > 0)
                    {
                        host = temp.Substring(0, start-1);
                        int end = start + 1;
                        while (end < temp.Length)
                        {
                            if (temp[end] < '0' || temp[end] > '9')
                                break;
                            end += 1;
                        }

                        var sub = temp.Substring(start, end - start);
                        int.TryParse(sub, out port);
                    }
                }

                Host = host;
                Port = port;
                ProxyUsername = Common.INIFile.ReadValue(PROXY_FILE, "Proxy", "user");

                temp = Common.INIFile.ReadValue(PROXY_FILE, "Proxy", "pass");
                if (!string.IsNullOrEmpty(temp))
                {
                    try
                    {
                        temp = AES256CBC.DecryptString(temp, ENCRYPTION_PASSWORD);
                    }
                    catch (Exception ex)
                    {
                        System.Diagnostics.Debug.WriteLine("Error in Common.WM.Net ReadProxyFile: " + ex.Message);
                        temp = "";
                    }
                }
                ProxyPassword = temp;

                return true;
            }
            catch (Exception ex)
            {
                System.Diagnostics.Debug.WriteLine("Error in Common.WM.Net ReadProxyFile: " + ex.Message);
                return false;
            }
        }

        public bool WriteProxyFile(Uri server, string user, string pwd)
        {
            try
            {
                Common.INIFile.WriteValue(PROXY_FILE, "Proxy", "server", server != null ? server.ToString() : "");
                Common.INIFile.WriteValue(PROXY_FILE, "Proxy", "user", user);

                if (!string.IsNullOrEmpty(pwd))
                {
                    pwd = AES256CBC.EncryptString(pwd, ENCRYPTION_PASSWORD);
                }
                Common.INIFile.WriteValue(PROXY_FILE, "Proxy", "pass", pwd);

                return true;
            }
            catch (Exception ex)
            {
                System.Diagnostics.Debug.WriteLine("Error in Common.WM.Net WriteProxyFile: " + ex.Message);
                return false;
            }
        }

        #endregion

        #region Encryption

        private const string ENCRYPTION_PASSWORD = "BHU*8iK,";

        //
        // EJB Aug-7-2014
        // this class was provided by Liem Nguyen
        // for encrypting/decrypting the password
        //
        private class AES256CBC
        {
            private AES256CBC() { }

            public static string EncryptString(string value, string password)
            {
                string sReturn = "";
                try
                {
                    RijndaelManaged aes = new RijndaelManaged();
                    aes.BlockSize = 128;
                    aes.KeySize = 256;

                    aes.Mode = CipherMode.CBC;
                    aes.Padding = PaddingMode.PKCS7;

                    byte[] keyArr = Convert.FromBase64String(Convert.ToBase64String(Encoding.ASCII.GetBytes(password)));
                    byte[] KeyArrBytes32Value = new byte[32];
                    Array.Copy(keyArr, KeyArrBytes32Value, keyArr.Length);

                    // Initialization vector. It could be any value or generated using a random number generator.
                    byte[] ivArr = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
                    byte[] IVBytes16Value = new byte[16];
                    Array.Copy(ivArr, IVBytes16Value, ivArr.Length);

                    aes.Key = KeyArrBytes32Value;
                    aes.IV = IVBytes16Value;

                    ICryptoTransform encrypto = aes.CreateEncryptor();

                    byte[] plainTextByte = ASCIIEncoding.UTF8.GetBytes(value);
                    byte[] CipherText = encrypto.TransformFinalBlock(plainTextByte, 0, plainTextByte.Length);

                    sReturn = Convert.ToBase64String(CipherText);
                }
                catch (Exception e)
                {
                    System.Diagnostics.Debug.WriteLine(e.Message.ToString());
                }
                return sReturn;
            }

            public static string DecryptString(string CipherText, string password)
            {
                string sReturn = "";
                try
                {
                    RijndaelManaged aes = new RijndaelManaged();
                    aes.BlockSize = 128;
                    aes.KeySize = 256;

                    aes.Mode = CipherMode.CBC;
                    aes.Padding = PaddingMode.PKCS7;

                    byte[] keyArr = Convert.FromBase64String(Convert.ToBase64String(Encoding.ASCII.GetBytes(password)));
                    byte[] KeyArrBytes32Value = new byte[32];
                    Array.Copy(keyArr, KeyArrBytes32Value, keyArr.Length);

                    // Initialization vector. It could be any value or generated using a random number generator.
                    byte[] ivArr = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

                    aes.Key = KeyArrBytes32Value;
                    aes.IV = ivArr;

                    ICryptoTransform decrypto = aes.CreateDecryptor();

                    byte[] encryptedBytes = Convert.FromBase64CharArray(CipherText.ToCharArray(), 0, CipherText.Length);
                    byte[] decryptedData = decrypto.TransformFinalBlock(encryptedBytes, 0, encryptedBytes.Length);

                    sReturn = ASCIIEncoding.UTF8.GetString(decryptedData);
                }
                catch (Exception ex)
                {
                    System.Diagnostics.Debug.WriteLine(ex.Message.ToString());
                }
                return sReturn;
            }

            private static string GetMacAddress()
            {
                const int MIN_MAC_ADDR_LENGTH = 12;
                string macAddress = string.Empty;
                long maxSpeed = -1;

                foreach (NetworkInterface nic in NetworkInterface.GetAllNetworkInterfaces())
                {
                    string tempMac = nic.GetPhysicalAddress().ToString();
                    if (nic.Speed > maxSpeed && !string.IsNullOrEmpty(tempMac) && tempMac.Length >= MIN_MAC_ADDR_LENGTH)
                    {
                        maxSpeed = nic.Speed;
                        macAddress = tempMac;
                    }
                }

                return macAddress;
            }
        }

        #endregion

        #region Singleton

        private static ConnectConfig _instance;
        private static object _sync = new Object();
        public static ConnectConfig Instance
        {
            get
            {
                if (_instance == null)
                {
                    lock (_sync)
                    {
                        if (_instance == null) _instance = new ConnectConfig();
                    }
                }
                return _instance;
            }
        }

        #endregion


    }
}
