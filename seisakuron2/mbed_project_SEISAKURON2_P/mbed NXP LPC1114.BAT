SET PATH=C:\Keil\ARM\ARMCC\bin\;C:\Program Files (x86)\Intel\iCLS Client\;C:\Program Files\Intel\iCLS Client\;C:\WINDOWS\system32;C:\WINDOWS;C:\WINDOWS\System32\Wbem;C:\WINDOWS\System32\WindowsPowerShell\v1.0\;C:\Program Files\Intel\Intel(R) Management Engine Components\DAL;C:\Program Files (x86)\Intel\Intel(R) Management Engine Components\DAL;C:\Program Files\Intel\Intel(R) Management Engine Components\IPT;C:\Program Files (x86)\Intel\Intel(R) Management Engine Components\IPT;C:\Program Files (x86)\Symantec\VIP Access Client\;C:\Program Files\Intel\WiFi\bin\;C:\Program Files\Common Files\Intel\WirelessCommon\;C:\Program Files\Microsoft SQL Server\110\Tools\Binn\;C:\Program Files (x86)\Skype\Phone\;C:\Program Files\MATLAB\R2016a\runtime\win64;C:\Program Files\MATLAB\R2016a\bin
SET CPU_TYPE=LPC1114/102
SET CPU_VENDOR=NXP (founded by Philips)
SET UV2_TARGET=mbed NXP LPC1114
SET CPU_CLOCK=0x00B71B00
"C:\Keil\ARM\ARMCC\bin\ArmCC" --Via ".\build\main.__i"
"C:\Keil\ARM\ARMCC\bin\ArmCC" --Via ".\build\softwarepwm.__i"
"C:\Keil\ARM\ARMCC\bin\ArmCC" --Via ".\build\motor.__i"
"C:\Keil\ARM\ARMCC\bin\ArmCC" --Via ".\build\sound.__i"
"C:\Keil\ARM\ARMCC\bin\ArmCC" --Via ".\build\qei.__i"
"C:\Keil\ARM\ARMCC\bin\ArmLink" --Via ".\build\mbed_project.lnp"
"C:\Keil\ARM\ARMCC\bin\fromelf.exe" ".\build\mbed_project.axf" --i32combined --output ".\build\mbed_project.hex"
fromelf --bin -o mbed_project_LPC1114.bin build\mbed_project.axf
