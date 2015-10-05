#include <stdio.h>
#include <stdlib.h>		// exit()
#include <unistd.h>
#include <wait.h>
#include <sys/types.h>

int count = 0;

int main() {

	int i, pid;

	printf("PID: %d\n", getpid());

	for(i = 0; i < 7; i++) {
		count++;
		pid = fork();
		if(pid == 0) {
			printf("PID: %d\tPPID: %d\n", getpid(), getppid());
		} else if(pid > 1) {
			wait(NULL);
			exit(0);
		}
	}

	printf("Count: %d\n", count);

	exit(0);
}
