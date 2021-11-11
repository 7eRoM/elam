# ELAM
A Practical example of ELAM (Early Launch Anti-Malware)

The ELAM feature provides a Microsoft-supported mechanism for antimalware (AM) software to start before other third-party components. AM drivers are initialized first and allowed to control the initialization of subsequent boot drivers, potentially not initializing unknown boot drivers. Once the boot process has initialized boot drivers and access to persistent storage is available in an efficient way, existing AM software may continue to block malware from executing. (Microsoft)

Here is a practical example of Microsoft ELAM. It's based on a code available on https://github.com/microsoft/Windows-driver-samples/tree/master/security/elam.

I added some simple code to the microsoft sample code in order to prevent loading a drive or running a service with a specific name in boot-time.

[![A Practical example of ELAM](http://img.youtube.com/vi/G_NgjZlr4e8/0.jpg)](http://www.youtube.com/watch?v=G_NgjZlr4e8 "A Practical example of ELAM")

**Useful commands**
```
"C:\Program Files (x86)\Windows Kits\10\bin\x64\makecert.exe" -a SHA256 -r -pe -ss PrivateCertStore -n "CN=MyElamCert" -eku 1.3.6.1.4.1.311.61.4.1,1.3.6.1.5.5.7.3.3 -sr localmachine C:\ELAM\x64\Debug\MyElamCert.cer

"C:\Program Files (x86)\Windows Kits\10\bin\x64\signtool.exe"  sign /fd SHA256 /a /v /ph /debug /s "PrivateCertStore" /n "MyElamCert" /tr http://sha256timestamp.ws.symantec.com/sha256/timestamp elamsample.sys

sc create ElamSample binpath=%windir%\\system32\\drivers\\elamsample.sys type=kernel start=boot error=critical group=Early-Launch

sc create GoodDriver binpath=%windir%\\system32\\drivers\\GoodDriver.sys type=kernel start=boot error=critical

sc create BadDriver binpath=%windir%\\system32\\drivers\\BadDriver.sys type=kernel start=boot error=critical
```
