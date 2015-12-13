/*
 * Exemplo de uso de fork. Quantos processos serão criados?
 * How many processes will be created?
 * g++ fork4.cpp -o fork4
 */

#include <cstdio>
#include <unistd.h>

int main() {

  fork();
  fork();

  printf("PID = %d\n", getpid());

  return 0;
}
