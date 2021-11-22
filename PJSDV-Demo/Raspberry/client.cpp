// Client side C/C++ program to demonstrate Socket programming
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#define PORT 8080
   
int connect(char* msg);

int main(int argc, char const *argv[])
{
    while(1) {
        char test[16];
        printf("Command: ");
        scanf("%s", test);
        // Add a new line char;
        strcat(test, "\n");

        printf("%s", test);
        connect(test);
    }
}

int connect(char* msg) {
int sock = 0, valread;
    struct sockaddr_in serv_addr;

    char buffer[1024] = {0};
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("\n Socket creation error \n");
        return -1;
    }
   
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
       
    // Convert IPv4 and IPv6 addresses from text to binary form
    if(inet_pton(AF_INET, "172.16.99.100", &serv_addr.sin_addr)<=0) 
    {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }
   
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        printf("\nConnection Failed \n");
        return -1;
    }

    send(sock , msg , strlen(msg) , 0 );
    valread = read(sock, buffer, 1024);
    printf("Received: %s\n", buffer);
    return 0;
}