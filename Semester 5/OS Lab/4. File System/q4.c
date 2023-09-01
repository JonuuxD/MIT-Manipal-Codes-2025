#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    char oldPath[100];
    char newPath[100];

    printf("Enter the existing file path: ");
    scanf("%s", oldPath);

    printf("Enter the path for the new symbolic link: ");
    scanf("%s", newPath);

    if (symlink(oldPath, newPath) == -1) {
        perror("Error creating symbolic link");
        exit(EXIT_FAILURE);
    }

    printf("Symbolic link created successfully at: %s\n", newPath);

    if (unlink(newPath) == -1) {
        perror("Error unlinking symbolic link");
        exit(EXIT_FAILURE);
    }

    printf("Symbolic link unlinked successfully.\n");

    return 0;
}
