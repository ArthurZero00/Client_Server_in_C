/*
Իմպլեմենտացնել ֆայլի փոխանցման համակարգ,
 որտեղ client-ը հարցում է ուղարկում ֆայլի անունով,
  իսկ server-ը հետ է ուղարկում ֆայլի պարունակությունը, եթե այն գոյություն ունի։
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};
    char file_buffer[BUFFER_SIZE];

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
        printf("Failed to accept\n");
        return 1;
    }

    read(new_socket, buffer, BUFFER_SIZE);
    printf("Client requested file: %s\n", buffer);

    FILE* fp = fopen(buffer, "r");
    if (fp == NULL) {
        char* msg = "File not found";
        send(new_socket, msg, strlen(msg), 0);
    } else {
        while (fgets(file_buffer, BUFFER_SIZE, fp) != NULL) {
            send(new_socket, file_buffer, strlen(file_buffer), 0);
            sleep(1); 
        }
        fclose(fp);
    }

    close(new_socket);
    close(server_fd);
    return 0;
}