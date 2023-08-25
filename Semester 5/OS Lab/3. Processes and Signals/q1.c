#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main() {
	int i = 0;
	pid_t pid = fork();
	do {
		if (pid == -1) {
			printf("Error creating child process\n");
		}
		else if (pid == 0) {
			printf("This is the child process\n");
		}
		else {
			wait();
			printf("This is the parent process\n");
		
		}
		i++;
	}while(i != 3);
}
