#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main() {
	pid_t pid = fork();

	if (pid == -1) {
		printf("Error with child process.");
	}
	else if (pid == 0) {
		printf("This is the child process\n");
		printf("Process id: %d, Parent id: %d\n", getpid(), getppid());
	}
	else {
		wait();
		printf("\nThis is the parent process\n");
		printf("Process id: %d, Parent id: %d\n", getpid(), getppid());
		printf("Child id: %d\n", pid);
	}
	return 0;
}
