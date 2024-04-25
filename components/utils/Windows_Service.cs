using System;
using System.Collections.Generic;
using System.Text;
using System.ServiceProcess;
using Microsoft.Win32;

namespace Common
{
    public class Service
    {
        public enum StartupType
        {
            Unknown=0,
            Automatic=2,
            Manual=3,
            Disabled=4
        }

        private ServiceController _controller;

        public StartupType Startup
        {
            get
            {
                try
                {
                    string keyName = "SYSTEM\\CurrentControlSet\\Services\\" + _controller.ServiceName;
                    RegistryKey key = Registry.LocalMachine.OpenSubKey(keyName, true);
                    if (key != null)
                    {
                        int? val = (int?)key.GetValue("Start");
                        if (val != null)
                        {
                            return (StartupType)val;
                        }
                    }
                }
                catch (Exception ex)
                {
                    System.Diagnostics.Debug.WriteLine("Error in Common.Net startup: " + ex.Message);
                }
                return StartupType.Unknown;
            }
            set
            {
                if (value == StartupType.Unknown) return;

                try
                {
                    string keyName = "SYSTEM\\CurrentControlSet\\Services\\" + _controller.ServiceName;
                    RegistryKey key = Registry.LocalMachine.OpenSubKey(keyName, true);
                    if (key != null)
                    {
                        key.SetValue("Start", (int)value);
                    }
                }
                catch (Exception ex)
                {
                    System.Diagnostics.Debug.WriteLine("Error in Common.Net Startup: " + ex.Message);
                }
            }
        }

        public ServiceControllerStatus Status
        {
            get { return _controller.Status; }
        }

        public Service(string name)
        {
            _controller = new ServiceController(name);

            if (_controller.ServiceName != name)
                // this is a dummy throw
                // _controller will throw the actual exception here
                throw (new System.InvalidOperationException()); 
        }

        public void Refresh()
        {
            try
            {
                _controller.Refresh();
            }
            catch (Exception ex)
            {
                System.Diagnostics.Debug.WriteLine("Error in Common.Net Refresh: " + ex.Message);
            }
        }

        public bool Start(int timeout_ms)
        {
            try
            {
                lock (_controller)
                {
                    switch (_controller.Status)
                    {
                        case ServiceControllerStatus.ContinuePending:
                        case ServiceControllerStatus.Running:
                        case ServiceControllerStatus.StartPending:
                            return true; // service is already running
                    }
                    _controller.Start();
                    _controller.Refresh(); // update the status
                }

                if (timeout_ms > 0)
                {
                    TimeSpan timeout = TimeSpan.FromMilliseconds(timeout_ms);
                    _controller.WaitForStatus(ServiceControllerStatus.Running, timeout);
                    _controller.Refresh(); // update the status
                }

                return true;
            }
            catch (Exception ex)
            {
                System.Diagnostics.Debug.WriteLine("Error in Common.Net Start: " + ex.Message);
                return false;
            }
        }

        public bool Stop(int timeout_ms)
        {
            try
            {
                lock (_controller)
                {
                    switch (_controller.Status)
                    {
                        case ServiceControllerStatus.Stopped:
                        case ServiceControllerStatus.StopPending:
                            return true; // service is already stopped
                    }

                    _controller.Stop();
                    _controller.Refresh(); // update the status
                }
                if (timeout_ms > 0)
                {
                    TimeSpan timeout = TimeSpan.FromMilliseconds(timeout_ms);
                    _controller.WaitForStatus(ServiceControllerStatus.Stopped, timeout);
                    _controller.Refresh(); // update the status
                }

                return true;
            }
            catch (Exception ex)
            {
                System.Diagnostics.Debug.WriteLine("Error in Common.Net Stop: " + ex.Message);
                return false;
            }
        }

        public bool Restart(int timeout_ms)
        {
            try
            {
                int millisec1 = Environment.TickCount;
                TimeSpan timeout = TimeSpan.FromMilliseconds(timeout_ms);

                if (Stop(timeout_ms))
                {
                    lock (_controller)
                    {
                        _controller.Start();
                        _controller.Refresh(); // update the status
                    }

                    if (timeout_ms > 0)
                    {
                        // count the rest of the timeout
                        int millisec2 = Environment.TickCount;
                        timeout = TimeSpan.FromMilliseconds(timeout_ms - (millisec2 - millisec1));

                        _controller.WaitForStatus(ServiceControllerStatus.Running, timeout);
                        _controller.Refresh(); // update the status
                    }
                    return true;
                }
            }
            catch (Exception ex)
            {
                System.Diagnostics.Debug.WriteLine("Error in Common.Net Restart: " + ex.Message);
            }
            return false;
        }
    }
}
