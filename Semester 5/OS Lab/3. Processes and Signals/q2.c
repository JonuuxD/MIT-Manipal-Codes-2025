#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>

int main() {
	pid_t pid = fork();

	if (pid == -1) {
		printf("Error creating the child process");
	}
	else if (pid == 0) {
		execlp("ping", "ping", "google.com", NULL);
	}
	else {
		wait();
		printf("Parent process - If this executes then your program has error.");
		exit(0);
	}
	return 0;
}
