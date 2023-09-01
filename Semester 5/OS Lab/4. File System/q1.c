#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>

int main() {
	char filename[100];
	printf("Enter the name of the file: ");
	scanf("%s", filename);

	struct stat file_stat;
	int return_value = stat(filename, &file_stat);
	if (return_value != 0) {
		perror("stat");
		return 1;
	}
	printf("File: %s got Inode: %ld\n", filename, file_stat.st_ino);
	return 0;
}
