/*
 * Exemplo de passagem de variáveis de ambiente

 * g++ envp.cpp -o envp
 */

#include <stdio.h>

int main(int argc, char** argv, char** envp) {

  int i;

  printf("O nome do programa é: %s\n", argv[0]);

  for (i = 1; i < argc; i++)
    printf("Argumento %d: %s\n", i, argv[i]);

  for (i = 0; envp[i]; i++)
    printf("Variável %d: %s\n", i, envp[i]);

  return 0;
}
