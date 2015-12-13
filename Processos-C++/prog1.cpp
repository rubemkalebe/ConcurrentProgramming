/*
 * Lab1 - Criacao de subprocessos usando C
 *
 *		A
 * 	   /
 *	  B
 *
 * Rubem Kalebe (2015.2)
 */
#include <stdio.h>
#include <stdlib.h>		// exit()
#include <unistd.h>
#include <wait.h>		// wait()

int main() {

	int pid, j, m;

	printf("PID: %d\n", getpid());

	pid = fork();

	if(pid == 0) {
		// Processo filho
		m = 50;
		printf("Processo filho\n");
		pid = getpid();
		printf("PID filho: %d\n", pid);
		for(j = 0; j < m; j++) {
			printf("Sou o Filho, meu PID eh: %d e J = %d\n", pid, j);
		}
		sleep(30);
		printf("Sou o Filho, meu PID eh: %d -- vou encerrar\n", pid);
		exit(0); // encerra execucao
	} else if(pid > 1) {
		// Processo pai
		//const int m = 100;
		const int m = 10;
		printf("Processo pai\n");
		pid = getpid();
		printf("PID pai: %d\n", pid);
		for(j = 0; j < m; j++) {
			printf("Sou o pai, meu PID eh: %d e J = %d\n", pid, j);
		}
		printf("---Vou executar o filho!\n");
		wait(NULL);
		printf("O filho encerrou, agora irei encerrar!\n");
	} else {
		// Falha -- o subprocesso nao foi criado
		printf("Falha ao criar novo subprocesso!!!\n");
		exit(1); // encerra execucao, com erro
	}
	
	exit(0); // encerra execucao

}