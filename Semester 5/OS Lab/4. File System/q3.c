#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
     if (link(argv[1], argv[2]) == -1) {
          perror("Error creating Hard link");
          exit(EXIT_FAILURE);
     }
    printf("Hard link created successfully at:  %s\n",argv[2]);

     if (unlink(argv[2]) == -1) {
          perror("Error unlinking Hard link");
          exit(EXIT_FAILURE);
    }

    printf("soft link unlinked successfully.\n");

    return 0;
}
