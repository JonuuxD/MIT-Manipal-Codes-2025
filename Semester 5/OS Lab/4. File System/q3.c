#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    char existingFile[100];
    char newLink[100];

    printf("Enter the existing file name: ");
    scanf("%s", existingFile);

    //newLink must be a new file
    printf("Enter the name for the new hard link: ");
    scanf("%s", newLink);

    if (link(existingFile, newLink) == -1) {
        perror("Error creating hard link");
        exit(EXIT_FAILURE);
    }

    printf("Hard link created successfully.\n");

    if (unlink(newLink) == -1) {
        perror("Error unlinking hard link");
        exit(EXIT_FAILURE);
    }

    printf("Hard link unlinked successfully.\n");

    return 0;
}
