/* server protype

   trivial thing... just the basic sctructure. */

#include <stdio.h>
#include <string.h>    //strlen
#include <sys/socket.h>
#include <arpa/inet.h> //inet_addr
#include <unistd.h>    //write

#define true 1
#define false 0

#define port 55765

int main(int argc, char **argv[])

{
    int socket_desc, client_sock, c, read_size;

    struct sockaddr_in server, client;

    char client_message[2000];

    //Create socket

    socket_desc = socket(AF_INET , SOCK_STREAM , 0);
    if (socket_desc == -1)

    {
        perror("Could not create socket");

    }

    puts("Socket created...\n");

    //Prepare the sockaddr_in structure

    memset(server.sin_zero, '\0', sizeof server.sin_zero); /*aloca espaço de memória para o PIPE socket. */
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(port); /* port allready defined */

    //Bind

    if( bind(socket_desc,(struct sockaddr *)&server , sizeof(server)) < 0)
    {
        //print the error message

        perror("bind failed. Error binding");
        return -1;

    }

     puts("\nbind done...\n");

    //Listen

    listen(socket_desc , 10);

    //Accept and incoming connection

    puts("\n** Waiting backdoor connect in\n");
    c = sizeof(struct sockaddr_in);

    //accept connection from an incoming client (backdoor)

    client_sock = accept(socket_desc, (struct sockaddr *)&client, (socklen_t*)&c);

    if (client_sock  == false)

    {
        perror("accept failed");
        return false;

    }

//  if (connect == true)
    puts("Connection accepted");

    }
