/*
 * Exemplo de uso de execve.
 * Executa o programa passado como argumento.

 * g++ execve1.cpp -o execve1

 * Exemplos:
     execve1 /bin/ls
     execve1 execve1 /bin/ls
 */

#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv, char **envp) {

  if (argc < 2) {
    fprintf (stderr, "Uso: %s cmd arg1 ... argn\n", argv[0]);
    return 1;
  }

  if (fork() == 0) {  /* Processo filho */
    printf("Novo filho\n");
    execve(argv[1], &argv[1], envp);
    fprintf(stderr,"Não conseguiu executar execve.\n");
    return 2;
  }
  else {                   /* Processo pai   */
    wait(NULL);
    printf ("Filho terminou sua execução.\n");
  }
  return 0;
}
