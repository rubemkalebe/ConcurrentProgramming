/*
 * Lab1 - Criacao de subprocessos usando C
 *
 *		A
 * 	   / \
 *	  B   C
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

		pid = fork(); // cria novo subprocesso a partir do filho

		if(pid == 0) {
			// Processo filho-filho
			m = 30;
			printf("Processo filho-filho\n");
			pid = getpid();
			printf("PID filho-filho: %d\n", pid);
			for(j = 0; j < m; j++) {
				printf("Sou o Filho-filho, meu PID eh: %d e J = %d\n", pid, j);
				//sleep(2);
			}
			printf("Sou o Filho-filho, meu PID eh: %d -- vou encerrar\n", pid);
			exit(0); // encerra execucao
		} else if(pid > 1) {
			// Processo filho-pai
			const int m = 10;
			printf("Processo filho-pai\n");
			pid = getpid();
			printf("PID filho-pai: %d\n", pid);
			for(j = 0; j < m; j++) {
				printf("Sou o filho-pai, meu PID eh: %d e J = %d\n", pid, j);
			}
			printf("---Vou executar o filho-filho!\n");
			wait(NULL);
			printf("O filho-filho encerrou, agora irei encerrar!\n");
		} else {
			// Falha -- o subprocesso nao foi criado
			printf("Falha ao criar novo subprocesso!!!\n");
			exit(1); // encerra execucao, com erro
		}

		//printf("Sou o Filho, meu PID eh: %d -- vou encerrar\n", pid);
		exit(0); // encerra execucao
	} else if(pid > 1) {
		// Processo pai
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