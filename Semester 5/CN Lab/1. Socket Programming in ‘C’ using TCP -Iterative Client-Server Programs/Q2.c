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

void removeDuplicates(char *str) {
    char words[MAX_SIZE][MAX_SIZE];
    int count = 0;
    
    char *token = strtok(str, " ");
    while (token != NULL) {
        int found = 0;
        for (int i = 0; i < count; i++) {
            if (strcmp(words[i], token) == 0) {
                found = 1;
                break;
            }
        }
        if (!found) {
            strcpy(words[count], token);
            count++;
        }
        token = strtok(NULL, " ");
    }
    
    str[0] = '\0'; // Clear the original string
    
    for (int i = 0; i < count; i++) {
        strcat(str, words[i]);
        if (i < count - 1) {
            strcat(str, " ");
        }
    }
}

int main() {
    int sockfd, newsockfd, portno, clilen, n;
    char buffer[MAX_SIZE];
    struct sockaddr_in seraddr, cliaddr;
    
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
            
            removeDuplicates(buffer);
            
            write(newsockfd, buffer, sizeof(buffer));
            close(newsockfd);
            exit(0);
        } else
            close(newsockfd);
    }
    return 0;
}

Client Code-

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
    
    do {
        printf("\nEnter a sentence (or 'Stop' to terminate): ");
        fgets(buffer, sizeof(buffer), stdin);
        buffer[strlen(buffer) - 1] = '\0'; // Remove newline
        
        write(sockfd, buffer, sizeof(buffer));
        
        n = read(sockfd, buffer, sizeof(buffer));
        printf("Modified sentence received from server: %s\n", buffer);
    } while (strcmp(buffer, "Stop") != 0);
    
    close(sockfd);
    return 0;
}
