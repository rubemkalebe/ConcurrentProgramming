/*
 * Criação de uma nova thread. Será que ela será sempre executada?
 * g++ thread1.cpp -o thread1 -pthread
 */
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void* f_thread(void *v) {
  printf("Nova Thread.\n");
  //sleep(5);
  return NULL;
}

int main() {
  pthread_t thr;

  if (pthread_create(&thr, NULL, f_thread, NULL))
    fprintf(stderr, "Erro na criação da thread. \n");

  /*for (int i = 0; i < 100; i++) {
    printf("Loop\n");
  }*/

  //sleep(5);

  return 0;
}
