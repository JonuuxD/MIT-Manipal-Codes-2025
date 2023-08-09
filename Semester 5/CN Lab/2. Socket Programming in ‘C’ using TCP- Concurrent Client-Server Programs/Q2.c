Server Code- 

#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <stdlib.h>

#define PORTNO 10200
#define MAX_SIZE 256

int performOperation(int a, int b, char operator) {
    switch (operator) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            if (b != 0)
                return a / b;
            else
                return 0;
        default:
            return -1; // Invalid operator
    }
}

int main() {
    int sockfd, newsockfd, portno, clilen, n;
    char buffer[MAX_SIZE];
    struct sockaddr_in seraddr, cliaddr;
    int i, value;
    
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    seraddr.sin_family = AF_INET;
    seraddr.sin_addr.s_addr = INADDR_ANY;
    seraddr.sin_port = htons(PORTNO);
    bind(sockfd, (struct sockaddr *)&seraddr, sizeof(seraddr));
    listen(sockfd, 5);
    
    while (1) {
        clilen = sizeof(cliaddr);
        newsockfd = accept(sockfd, (struct sockaddr *)&cliaddr, &clilen);
        if (fork() == 0) {
            n = read(newsockfd, buffer, sizeof(buffer));
            int num1, num2, result;
            char operator;
            
            sscanf(buffer, "%d %c %d", &num1, &operator, &num2);
            
            result = performOperation(num1, num2, operator);
            snprintf(buffer, sizeof(buffer), "Result: %d\n", result);
            
            write(newsockfd, buffer, sizeof(buffer));
            close(newsockfd);
            exit(0);
        } else
            close(newsockfd);
    }
    return 0;
}

Client Code -

#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> 

#define MAX_SIZE 256

int main() {
    int len, result, sockfd, n = 1;
    struct sockaddr_in address;
    char buffer[MAX_SIZE];
    
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = inet_addr("127.0.0.1");
    address.sin_port = htons(10200);
    len = sizeof(address);
    
    result = connect(sockfd, (struct sockaddr *)&address, len);
    if (result == -1) {
        perror("\nCLIENT ERROR");
        exit(1);
    }
    
    printf("Enter two integers and an operator (e.g., 5 + 3): ");
    fgets(buffer, sizeof(buffer), stdin);
    
    write(sockfd, buffer, sizeof(buffer));
    
    n = read(sockfd, buffer, sizeof(buffer));
    printf("Result received from server: %s\n", buffer);

    close(sockfd);
    return 0;
}
