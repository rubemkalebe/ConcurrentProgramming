#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main() {

	int pipeFd[3];

	if(pipe(pipeFd) == -1) {
		perror("Erro ao criar pipe");
		return -1;
	}

	int idProcesso = fork();

	if(idProcesso == 0) {
		idProcesso = fork();
		if(idProcesso == 0) {
			close(pipeFd[2]);
			close(pipeFd[0]);
			char buffer[255];
			while(1) {
				int bytesLidos = read(pipeFd[0], buffer, 255);
				buffer[bytesLidos] = '\0';
				printf("%d: %s\n", getpid(), buffer);
			}
		} else {
			close(pipeFd[1]);
			close(pipeFd[2]);
			char buffer[255];
			while(1) {
				int bytesLidos = read(pipeFd[0], buffer, 255);
				buffer[bytesLidos] = '\0';
				printf("%d: %s\n", getpid(), buffer);
			}
		}
	} else {
		close(pipeFd[0]);
		char buffer[255];
		while(1) {
			scanf("%s", buffer);
			write(pipeFd[1], buffer, strlen(buffer));
		}
	}

}