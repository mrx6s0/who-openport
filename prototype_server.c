/* server protype */

#include <stdio.h>
#include <string.h>    //strlen
#include <sys/socket.h>
#include <arpa/inet.h> //inet_addr
#include <unistd.h>    //write

#define true 1
#define false 0

#define port 55766

int main(int argc , char **argv[])

{
    int socket_desc , client_sock , c , read_size;

    struct sockaddr_in server , client;

    char client_message[2000];

    //Create socket

    socket_desc = socket(AF_INET , SOCK_STREAM , 0);
    if (socket_desc == -1)
    {
        perror("Could not create socket");
    }
    puts("\nSocket created [*]\n");

    //Prepare the sockaddr_in structure

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons( 55766 ); /* port allready defined */

    //Bind

    if( bind(socket_desc,(struct sockaddr *)&server , sizeof(server)) < 0)
    {
        //print the error message

        perror("bind failed. Error binding");
        return -1;
    }

    puts("\nbind done [*]\n");

    //Listen

    listen(socket_desc , 10);

    //Accept and incoming connection

    puts("\n[**] Waiting for incoming connections...\n");
    c = sizeof(struct sockaddr_in);

    //accept connection from an incoming client

    client_sock = accept(socket_desc, (struct sockaddr *)&client, (socklen_t*)&c);

    if (client_sock <= -1)

    {
        perror("accept failed");
        return 0x01;

    }

    connect == 1;
    puts("Connection accepted");

    }
