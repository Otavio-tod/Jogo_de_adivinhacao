#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void)
{
    
        int chute = 0;
        srand(time(NULL));
        int x = (rand() % 100) + 1;
    do
    {
        printf("Digite o seu chute: ");
        if (scanf("%d", &chute) != 1)
        {
            printf("\n[ERRO] Entrada invalida! Digite apenas numeros.\n");
            while (getchar() != '\n');

            chute = 0;
            continue;
        }
        if (chute == x)
        {
            printf("Isso, acertou o chute do numero ");
        }
        else
        {
            printf("Nao foi dessa vez, voce nao acertou o chute, tente denovo ");
        }
    } while ( chute != x);
    return 0;
}