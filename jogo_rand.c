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
        printf("\nDigite o seu chute: ");
        if (scanf("%d", &chute) != 1)
        {
            printf("\n[ERRO] Entrada invalida! Digite apenas numeros.\n");
            while (getchar() != '\n');

            chute = 0;
            continue;
        }
        if (chute == 0)
        {
            printf("Saindo");
            break;
        }
        if (chute == x)
        {
            printf("Isso, acertou o chute do numero. ");
        }
        else
        {
            if (chute > x)
            {
                printf("Chutou alto. ");
            }
            else
            {
                printf("Chutou baixo. ");
            }
        }
    } while ( chute != x);
    return 0;
}