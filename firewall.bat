@echo off
c:\windows\system32\netsh firewall set opmode mode = disable
netsh advfirewall set allprofiles state off
exit
