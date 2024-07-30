#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <locale.h>

// regra inversão dos 2 ultimos bits
void regra1(char *bin)
{
    if (bin[6] == '1')
    {
        bin[6] = '0';
    }
    else if (bin[6] == '0')
    {
        bin[6] = '1';
    }

    if (bin[7] == '1')
    {
        bin[7] = '0';
    }
    else if (bin[7] == '0')
    {
        bin[7] = '1';
    }
}

// regra troca 4 a 4
void regra2(char *bin)
{
    for (int i = 0; i < 4; i++)
    {
        char temp = bin[i];
        bin[i] = bin[i + 4];
        bin[i + 4] = temp;
    }
}

// conversor de bin pra decimal
int binDec(char bin[])
{
    int tamanho = strlen(bin);
    int soma = 0;

    for (int i = 0; i < tamanho; i++)
    {
        soma += (bin[i] - '0') * pow(2, tamanho - (1 + i));
    }

    return soma;
}

void descriptografia(char msg[])
{
    int tamanho = strlen(msg) + 1;
    char temp[9];
    char *pontTemp = temp;
    int contador = 0;

    //monta os bits da mensagem
    for (int i = 0; i < tamanho; i++)
    {
        // aplica as regras e converte o valor
        // as regras são aplicadas quando chega no espaço entre as linhas ou quando é o fim da msg
        if (msg[i] == ' ' || i == tamanho-1)
        {
            regra1(pontTemp);

            regra2(pontTemp);
            printf("%c", binDec(temp));

            contador++;

            continue;
        }
        // seta o byte para ser convertido
        temp[i - 9 * contador] = msg[i];
    }
}

int main(void)
{
    char msg[] = "10010110 11110111 01010110 00000001 00010111 00100110 01010111 00000001 00010111 01110110 01010111 00110110 11110111 11010111 01010111 00000011";

    descriptografia(msg);

}
