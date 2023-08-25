#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main() {
	pid_t pid = fork();
	if (pid == -1) {
		printf("Error creating the child process");
	}
	else if (pid == 0) {
		printf("This is the child process.\n");
	}
	else {
		sleep(3);
		printf("This is the parent process.");
	}
	return 0;
}

// use "./a.out &" to execute and type ps in the terminal as soon as you
// start the program inorder to check the defunct(zombie) child.
