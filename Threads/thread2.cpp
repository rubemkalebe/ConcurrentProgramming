/*
 * Criação de uma nova thread. O comando join garante que a thread main irá
 * esperar pelo fim da execução da nova thread.
 * g++ thread2.cpp -o thread2 -pthread
 */
#include <pthread.h>
#include <stdio.h>

void* f_thread(void *v) {
  printf("Nova Thread.\n");
  return NULL;
}

int main() {
  pthread_t thr;

  if (pthread_create(&thr, NULL, f_thread, NULL))
    fprintf(stderr, "Erro na criação da thread.\n");

  if (pthread_join(thr, NULL))
    fprintf(stderr, "Erro na espera pela thread.\n");

  return 0;
}
