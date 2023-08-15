#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{

    printf("****************************\n");
    printf("*****bem vindo ao jogo!*****\n");
    printf("****************************\n");

    int segundos = time(0);
    srand(segundos);

    int numero_grande = rand();

    int numero_misterioso = numero_grande % 100;
    int chute;
    int tentativas = 1;
    double pontos = 1000;

    int acertou = 0;

    int nivel;
    printf("Selecione o nivel de dificuldade\n");
    printf("(1) facil demais (2) Dificuldade: medo :o  (3)Dificuldade: Fumo\n");
    printf("escolha ");
    scanf("%d", &nivel);

    int numero_de_tentativas;

    switch (nivel)
    {
    case 1:
        numero_de_tentativas = 12;
        break;

    case 2:
        numero_de_tentativas = 9;
        break;

    default:
        numero_de_tentativas = 6;
        break;
    }

    for (int i = 1; i <= numero_de_tentativas; i++)
    {
        printf("Tentativa %d\n", tentativas);
        printf("Qual o chute, paizao? ");

        scanf("%d", &chute);
        printf("Seu chute foi %d\n", chute);

        if (chute < 0)
        {
            printf("so conta numero positivo, animal\n");
            continue;
        }

        acertou = (chute == numero_misterioso);
        int maior = chute > numero_misterioso;

        if (acertou)
        {
            break;
        }
        else if (maior)
        {
            printf("Chutou alto, chuta um mais baixo, animal\n");
        }
        else
        {
            printf("Chutou baixao filho, aumenta ai \n");
        }

        tentativas++;
        double pontosperdidos = abs(chute - numero_misterioso) / (double)2;
        {
            pontos = pontos - pontosperdidos;
        }
    }
    printf("\nFim de jogo\n");

    if (acertou)
    {
        printf("Acertou, mizeravi");
        printf("Acertou em %d tentativas\n", tentativas++);
        printf("total de pontos: %.1f\n", pontos);
    }

    else
    {
        printf("Errou... Burrao\n");
    }
}
