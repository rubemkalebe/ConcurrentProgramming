#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void trata2(int sinal)
{
   printf("Tu nao eh um bom usuario. Cansei de esperar!\n");
   raise(15);
/* a funcao raise envia um sinal para eu mesmo. No caso estou enviando o sinal 15, que como não foi tratado encerra o programa.

raise (sinal) é um alias praticamente para kill(getpid(), sinal). Inclusive o man dele diz isto (man raise)
*/
}

void trata1(int sinal)
{
   printf("Ta, vou esperar a vida toda? Tem mais 3 segundos!\n");

   /* Redefine o sinal SIGALRM para outra funcao */

   signal(SIGALRM, trata2);
   alarm(3); // agenda 3 segundos
}

int main()
{
   int a;
   signal(SIGALRM, trata1);
   //signal(SIGALRM, SIG_IGN); // Ignora sinal

   printf("Meu pid eh %i\n", getpid());

   alarm(5); // agenda 5 segundos para disparar o sinal SIGALRM

   printf("Digite um numero: \n");
   scanf("%i", &a);

   alarm(0); // cancela agendamento

   printf("Obrigado.\n");
   return(0);
}
