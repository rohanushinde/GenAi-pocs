import android.Manifest
import android.content.Context
import android.content.pm.PackageManager
import android.os.Build
import android.telephony.TelephonyManager

fun getDeviceImei(context: Context): String? {
    // This function works on Android 11 and below
    if (Build.VERSION.SDK_INT <= Build.VERSION_CODES.R) {
        val telephonyManager = context.getSystemService(Context.TELEPHONY_SERVICE) as TelephonyManager
        return telephonyManager.deviceId
    } else {
        // For Android 13 and above, this function will not work
        return null
    }
}

// New function introduced in Android 13
fun getDeviceImeiAndroid13(context: Context): String? {
    // Check if the READ_PRIVILEGED_PHONE_STATE permission is granted
    if (context.checkSelfPermission(Manifest.permission.READ_PRIVILEGED_PHONE_STATE) == PackageManager.PERMISSION_GRANTED) {
        val telephonyManager = context.getSystemService(Context.TELEPHONY_SERVICE) as TelephonyManager
        return telephonyManager.getImei()
    }
    return null
}
