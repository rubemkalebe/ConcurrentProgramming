#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define N 3

void* print(void* arg) {
	int *n = (int*) arg;
	printf("Thread = %d\n", *n);

	int i,j;

	for (i=0;i<50000;i++)

	j+=i;

	//pthread_exit(NULL);

	pthread_exit((void*)2);
}

int main() {

	pthread_t threads[N];
	int s[] = {10, 20, 30}, i, estado;

	pthread_attr_t attr;
	pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

	for (i = 0; i < N; i++) {
		printf("Criando thread %d...\n", i);
		if(pthread_create(&threads[i], &attr, print, (void*) &s[i])) {
			printf("Erro ao criar o thread %d\n", i);
			exit(-1);
		}
	}
	
	pthread_attr_destroy(&attr);

	for(i = 0; i < N; i++) {
		if(pthread_join(threads[i], (void**) &estado)) {
			printf("--ERRO: pthread_join()\n");
			exit(-1);
		}
		printf("i: %d\n", estado);
	}

	printf("Main thread terminando...\n");
	pthread_exit(NULL);

}