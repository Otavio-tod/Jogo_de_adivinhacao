#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void)
{
    
        int chute;
        srand(time(NULL));
        int x = (rand() % 100) + 1;
    do
    {
        printf("Digite o seu chute: ");
        scanf("%d", &chute);
        printf("%d\n", x);
        if (chute == x)
        {
            printf("Isso, acertou o chute do numero ");
        }
        else
        {
            printf("Nao foi dessa vez, voce nao acertou o chute, tente denovo ");
        }
    } while ( chute = x);
    return 0;
}