Server Code-

#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORTNO 10200
#define MAX_SIZE 100

void insertionSort(int arr[], int size) {
    int i, key, j;
    for (i = 1; i < size; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main() {
    int sockfd, newsockfd, portno, clilen, n = 1;
    int arr[MAX_SIZE];
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
            n = read(newsockfd, arr, sizeof(arr));
            int size = n / sizeof(int); // Calculate the number of integers
            insertionSort(arr, size);   // Sort the array
            write(newsockfd, arr, sizeof(arr));
            
            // Send the child process ID to the client
            snprintf(arr, sizeof(arr), "Sorted by Process ID %d", getpid());
            write(newsockfd, arr, sizeof(arr));
            
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
#include <unistd.h> // For getpid()

#define MAX_SIZE 100

int main() {
    int len, result, sockfd, n = 1;
    struct sockaddr_in address;
    char buf[256];
    int arr[MAX_SIZE];
    
    // Create a socket for the client
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = inet_addr("127.0.0.1");
    address.sin_port = htons(10200);
    len = sizeof(address);
    
    // Connect your socket to the server's socket
    result = connect(sockfd, (struct sockaddr *)&address, len);
    if (result == -1) {
        perror("\nCLIENT ERROR");
        exit(1);
    }
    
    printf("Enter the number of integers: ");
    int num;
    scanf("%d", &num);
    
    printf("Enter %d integers: ", num);
    for (int i = 0; i < num; i++) {
        scanf("%d", &arr[i]);
    }
    
    // Send the array to the server
    write(sockfd, arr, num * sizeof(int));
    
    // Receive and display the sorted array
    n = read(sockfd, arr, sizeof(arr));
    for (int i = 0; i < n / sizeof(int); i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    // Receive and display the process ID information
    n = read(sockfd, buf, sizeof(buf));
    printf("Process ID: %s\n", buf);

    return 0;
}
