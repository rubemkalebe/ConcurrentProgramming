#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <cstring>

#define NUMTHREADS 2
#define VETSIZE 5000

typedef struct {
	int fromidx, length;
} thread_arg, *ptr_thread_arg;

pthread_t threads[NUMTHREADS];
thread_arg arguments[NUMTHREADS];
int nums[VETSIZE];
int sum;
int globalIndex = 0;

void *thread_func(void *arg) {
	ptr_thread_arg argument = (ptr_thread_arg) arg;
	int i, localsum = 0, endix;
	endix = arguments->fromidx + arguments->length;

	/*for (i = 0; i < endix; ++i) {
		//localsum += nums[i];
		sum += nums[i];
	}*/
	/*while(globalIndex < endix) {
		localsum += nums[globalIndex];
		globalIndex++;
	}*/
	for ( ; globalIndex < endix; globalIndex++) {
		localsum += nums[globalIndex];
	}
	sum += localsum;
	//sum += localsum;
	//printf("here %d\n", pthread_self());
}

int main() {

	int i, length, remainder;

	sum = 0;

	length = VETSIZE / NUMTHREADS;

	remainder = VETSIZE % NUMTHREADS;

	for(i = 0; i < VETSIZE; i++) {
		nums[i] = 1;
	}

	for (i = 0; i < NUMTHREADS; ++i) {
		arguments[i].fromidx = i*length;
		arguments[i].length = length;
		if(i == (NUMTHREADS - 1)) arguments[i].length += remainder;
		pthread_create(&(threads[i]), NULL, thread_func, &(arguments[i]));
	}

	for (i = 0; i < NUMTHREADS; ++i) {
		pthread_join(threads[i],NULL);
	}

	printf("A soma dos números do vetor eh: %d\n", sum);

	pthread_exit(NULL);
}
