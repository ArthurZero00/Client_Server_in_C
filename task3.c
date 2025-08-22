/*
Իմպլեմենտացնել Client-Server ծրագիր, որտեղ client-ը server-ին անվերջ ցիկլով  ուղարկում է user-ի կողմից 
մուտքագրված թիվ,  սերվերը ստուգում է՝ արդյոք  տվյալ թիվը համարվում է Արմսթրոնգի թիվ,
 թե ոչ։ Եթե համապատասխանում է պահանջներին  server-ը որպես պատասխան client-ին ուղարկում է “Yes”, հակառակ դեպքում “No”։
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <netinet/in.h>
#include <math.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int is_armstrong(int num) {
    int original = num, sum = 0, digits = 0, temp = num;
    while (temp > 0) {
        digits++;
        temp /= 10;
    }
    temp = num;
    while (temp > 0) {
        int digit = temp % 10;
        sum += pow(digit, digits);
        temp /= 10;
    }
    return sum == original;
}

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    char buffer[BUFFER_SIZE];
    int addrlen = sizeof(address);

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    bind(server_fd, (struct sockaddr*)&address, sizeof(address));
    listen(server_fd, 1);

    printf("Server listening on port %d...\n", PORT);
    new_socket = accept(server_fd, (struct sockaddr*)&address, (socklen_t*)&addrlen);

    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        int bytes = read(new_socket, buffer, BUFFER_SIZE);
        if (bytes <= 0) break;

        int number = atoi(buffer);
        printf("Received: %d\n", number);

        if (is_armstrong(number)) {
            send(new_socket, "Yes", 3, 0);
        } else {
            send(new_socket, "No", 2, 0);
        }
    }

    close(new_socket);
    close(server_fd);
    return 0;
}