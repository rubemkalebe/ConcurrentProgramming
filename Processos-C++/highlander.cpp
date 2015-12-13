#include <signal.h>
#include <unistd.h>
#include <stdio.h>

void morroNao(int sinal)
{
    printf("\n\n***** O seu MANE, eu sou imortal *****\n");
    printf("***** Nao eh por causa do sinalzinho %i que vou perecer!!\n\n", sinal);
}

int main()
{
    char c;
    int s;
    for (s=1; s<35; s++){
            signal(s, morroNao);
    }
    while (1) {
        printf("qua qua qua. Ainda to vivo. Meu pid eh %i\n", getpid());
        sleep(3);
    }
    return 0;
}
