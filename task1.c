/*Իրականացնել Client-Server ծրագիր, որտեղ client-ը server-ին ուղարկում է տող, 
 server-ն այն ընդունում է, ձևափոխված ուղարկում է client-ին՝ որպես պատասխան։

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <netinet/in.h>
#define PORT 8080
#define BUFFER_SIZE 1024

void to_uppercase(char* str) {
    while (*str) {
        *str = toupper((unsigned char)*str);
        str++;
    }
}

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    char buffer[BUFFER_SIZE] = {0};
    int addrlen = sizeof(address);

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1) {
        printf("Socket creation failed\n");
        return 1;
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    bind(server_fd, (struct sockaddr*)&address, sizeof(address));
    listen(server_fd, 3);

    printf("Server is waiting for connection...\n");

    new_socket = accept(server_fd, (struct sockaddr*)&address, (socklen_t*)&addrlen);
    if (new_socket < 0) {
        printf("Connection failed\n");
        return 1;
    }

    read(new_socket, buffer, BUFFER_SIZE);
    printf("Received from client: %s\n", buffer);

    to_uppercase(buffer);
    send(new_socket, buffer, strlen(buffer), 0);
    printf("Modified and sent back: %s\n", buffer);

    close(new_socket);
    close(server_fd);

    return 0;
}