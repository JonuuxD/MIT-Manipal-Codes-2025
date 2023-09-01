#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    char filename[100];

    printf("Enter the filename: ");
    scanf("%s", filename);

    struct stat fileStat;

    if (stat(filename, &fileStat) == -1) {
        perror("Error");
        exit(0);
    }

    printf("File Information for: %s-----------\n", filename);
    printf("Inode Number: %ld\n", (long)fileStat.st_ino);
    printf("Device ID: %ld\n", (long)fileStat.st_dev);
    printf("File Type and Mode: %o\n", fileStat.st_mode);
    printf("Number of Hard Links: %ld\n", (long)fileStat.st_nlink);
    printf("User ID of Owner: %ld\n", (long)fileStat.st_uid);
    printf("Group ID of Owner: %ld\n", (long)fileStat.st_gid);
    printf("File Size (in bytes): %ld\n", (long)fileStat.st_size);
    printf("Block Size for I/O: %ld\n", (long)fileStat.st_blksize);
    printf("Number of Blocks Allocated: %ld\n", (long)fileStat.st_blocks);
    printf("Last Access Time: %ld\n", (long)fileStat.st_atime);
    printf("Last Modification Time: %ld\n", (long)fileStat.st_mtime);
    printf("Last Status Change Time: %ld\n", (long)fileStat.st_ctime);

    return 0;
}
