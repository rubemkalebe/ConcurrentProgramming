#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdint.h>
#include <unistd.h>

#define NTHREADS 30

// funcao executada pelas threads
//void* PrintHello(int* threadID) {
//void* PrintHello(void* threadID) {
void* PrintHello(void* threadID) {
	int *tid = (int*) threadID;
	printf("Hello World da thread: %d\n", *tid);
	//printf("Hello World da thread: %d\n", (int) threadID);
}

// funcao principal
int main(int argc, char const *argv[]) {

	pthread_t tid[NTHREADS];
  int v[NTHREADS];
	int t;

  for(int i = 0; i < NTHREADS; i++) {
    v[i] = i;
  }

	for(t = 0; t < NTHREADS; t++) {
		printf("--Cria thread %d\n", t);
		if(pthread_create(&tid[t], NULL, PrintHello, (void*) &v[t])) {
		//if(pthread_create(&tid[t], NULL, PrintHello, (void *) ((intptr_t) t))) {
			printf("--ERRO: pthread_create()\n");
			exit(-1);
		}
    //sleep(1);
	}

	//sleep(10);

	// espera as threads terminarem
	for(t = 0; t < NTHREADS; t++) {
		if(pthread_join(tid[t], NULL)) {
			printf("--ERRO: pthread_join()\n");
			exit(-1);
		}
	}

	printf("Thread principal terminou\n");

	pthread_exit(NULL);
}
