/*
 * Escreve uma mensagem antes de ser interrompido.
 */

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void trata_SIGINT(int signum) {
  printf("Fui interrompido!\n");
  signal(SIGINT, SIG_DFL);
  raise(SIGINT);
}

int main() {
  printf("Meu pid é: %d\n", getpid());
  signal(SIGINT, trata_SIGINT);
  while (1)
    sleep(1);

  return 0;
}
