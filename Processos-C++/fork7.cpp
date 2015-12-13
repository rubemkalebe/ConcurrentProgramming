/*
 * Exemplo de hierarquia de processos              A
 *  e uso de fork e wait                          / \
 *                                              B     C
 *                                             /|\
 *                                            D E F
 */
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>

int main() {
  int i;

  if (fork())  /* Processo A */
    if (fork()) {
      for (i = 0; i < 2; i++)
	wait(NULL); /* Espera a morte de dois filhos */
      printf("Processo A\n");
    }
    else
      printf("Processo C\n");
  else  /* Processo B */
    if (fork())
      if (fork())
	if (fork()) {
	  for (i = 0; i < 3; i++) {
      sleep(10);
      wait(NULL); /* Espera a morte de trÃªs filhos */
    }
	  printf("Processo B\n");
	}
	else
	  printf("Processo F\n");
      else
	printf("Processo E\n");
    else
      printf("Processo D\n");
  return 0;
}
