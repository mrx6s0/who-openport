/* server prototype

   trivial thing... just the basic sctructure. */

#include <stdio.h>
#include <string.h>    //strlen
#include <sys/socket.h>
#include <arpa/inet.h> //inet_addr
#include <unistd.h>    //write

#define true 1
#define false 0

#define remote_port 55765
#define remote_target INADDR_ANY

int main(int argc, char **argv[])

{
    int target, target_sock, c, read_size;

    struct sockaddr_in server, client;

    char data_backdoor[2000];

    //Create socket

    target = socket(AF_INET , SOCK_STREAM , 0);
    if (target == -1)

    {
        perror("Could not create socket");

    }

    puts("Socket created...\n");

    //Prepare the sockaddr_in structure

    memset(server.sin_zero, '\0', sizeof server.sin_zero); /*aloca espaço de memória para o PIPE socket. */
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = (remote_target);
    server.sin_port = htons(remote_port); /* port allready defined */

    //Bind

    if( bind(target,(struct sockaddr *)&server , sizeof(server)) < 0)
    {
        //print the error message

        perror("bind failed. Error binding");
        return -1;

    }

     puts("\nbind done...\n");

    //Listen

    listen(target, 10);

    //Accept and incoming connection

    puts("\n** Waiting backdoor connect in **\n");
    c = sizeof(struct sockaddr_in);

    //accept connection from an incoming client (backdoor)

    target_sock = accept(socket_desc, (struct sockaddr *)&target, (socklen_t*)&c);

    if (target_sock  == false)

    {
        perror("accept failed");
        return false;

    }

    puts("Connection accepted");

    }
