#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void)
{
    int chute = 0;
    srand(time(NULL));                // semente: hora atual (numero muda a cada execucao)
    int x = (rand() % 100) + 1;       // secreto de 1 a 100 (sorteado uma vez, fora do laco)
    do                                // executa primeiro, confere depois
    {
        printf("\nDigite o seu chute: ");
        if (scanf("%d", &chute) != 1) // scanf devolve quantos numeros leu; != 1 = nao era numero
        {
            printf("\n[ERRO] Entrada invalida! Digite apenas numeros.\n");
            while (getchar() != '\n'); // faxineiro: apaga a entrada ate o Enter (evita loop infinito)

            chute = 0;                // valor seguro: nunca e igual ao secreto
            continue;                 // vai direto para a condicao do while
        }
        if (chute == 0)               // == compara (um = so atribuiria)
        {
            printf("Saindo");
            break;                    // sai do laco na hora
        }
        if (chute == x)
        {
            printf("Isso, acertou o chute do numero. ");
        }
        else                          // aqui o chute ja esta errado: so falta ver o lado
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
    } while ( chute != x);            // repete enquanto errar
    return 0;
}