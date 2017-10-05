set shell=CreateObject("Shell.Application")
shell.ShellExecute "firewall.bat",,"C:\\", "runas", 0 
set shell=nothing 
