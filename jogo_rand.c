// ============================================================
// JOGO DE ADIVINHACAO
// O computador sorteia um numero secreto de 1 a 100.
// O jogador chuta ate acertar (ou digita 0 para sair).
// A cada chute errado, o jogo diz se foi alto ou baixo.
// ============================================================

// stdio.h: traz printf, scanf e getchar (entrada e saida)
#include <stdio.h>
// time.h: traz a funcao time(), que le a hora do computador
#include <time.h>
// stdlib.h: traz rand() e srand() (numeros aleatorios)
#include <stdlib.h>

int main(void)
{
    // Guarda o chute do jogador.
    // Comeca valendo 0 para nunca ter "lixo de memoria" dentro dela.
    int chute = 0;

    // Muda a "semente" do sorteio usando a hora atual (em segundos).
    // Sem isso, o rand() daria o mesmo numero em toda execucao.
    // Fica ANTES do laco: o sorteio acontece uma vez so.
    srand(time(NULL));

    // Numero secreto:
    // rand()       -> numero aleatorio grande
    // % 100        -> resto da divisao por 100 (fica entre 0 e 99)
    // + 1          -> desloca para 1 a 100
    // Fica fora do laco para o secreto NAO mudar a cada chute.
    int x = (rand() % 100) + 1;

    // do-while: executa o bloco PRIMEIRO e confere a condicao DEPOIS.
    // Aqui encaixa bem: o chute precisa ser pedido pelo menos uma vez.
    do
    {
        // \n no comeco deixa uma linha em branco entre as rodadas
        printf("\nDigite o seu chute: ");

        // O scanf devolve QUANTOS valores ele conseguiu ler.
        // Pedimos 1 numero (%d). Se nao devolveu 1, a pessoa
        // digitou algo que nao e numero (letra, Esc, etc).
        // &chute = endereco da variavel, onde o scanf guarda o numero.
        if (scanf("%d", &chute) != 1)
        {
            printf("\n[ERRO] Entrada invalida! Digite apenas numeros.\n");

            // "Faxineiro": a letra digitada fica parada na entrada.
            // Sem limpar, o scanf leria a mesma letra para sempre
            // (loop infinito). O getchar() le um caractere por vez;
            // o while repete ate chegar no Enter ('\n'), jogando
            // tudo fora. O ; sozinho e o corpo vazio do while.
            while (getchar() != '\n');

            // Deixa o chute com um valor conhecido (0). Como o secreto
            // vai de 1 a 100, o 0 nunca e igual a ele.
            chute = 0;

            // Pula para a CONDICAO do while (chute != x). Como o chute
            // e 0, a condicao e verdadeira e o jogo pede de novo.
            // Este continue pula tambem os ifs abaixo, de proposito:
            // o 0 desta limpeza NAO deve contar como pedido de saida.
            continue;
        }

        // Saida: so chega aqui se o jogador digitou um NUMERO valido.
        // == compara (pergunta "e igual a zero?"). Um = so atribuiria.
        if (chute == 0)
        {
            printf("Saindo");

            // break: sai do laco na hora, sem conferir o while.
            // (continue volta para o laco; break sai dele.)
            break;
        }

        // O jogador acertou? (chute IGUAL ao secreto)
        if (chute == x)
        {
            printf("Isso, acertou o chute do numero. ");
        }
        else
        {
            // Se caiu aqui, o chute ja esta ERRADO (diferente de x).
            // Entao so falta saber de que lado ele errou.
            // Por isso basta perguntar "maior?": se nao e maior,
            // so pode ser menor.
            if (chute > x)
            {
                printf("Chutou alto. ");
            }
            else
            {
                printf("Chutou baixo. ");
            }
        }

        // Condicao do laco: "o jogo continua?"
        // Repete ENQUANTO o chute for DIFERENTE do secreto (!=).
        // Quando acerta, a condicao vira falsa e o laco termina.
    } while ( chute != x);

    // Fim do programa. 0 = terminou sem erro.
    return 0;
}