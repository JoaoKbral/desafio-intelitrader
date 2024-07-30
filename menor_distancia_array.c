#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void comparador(int *temp, int valor1, int valor2, int *numA, int *numB)
{
    if (*temp > abs(valor1 - valor2))
    {
        *temp = abs(valor1 - valor2);
        *numA = valor1;
        *numB = valor2;
    }
}


int main(void)
{
    // descomentar para o rand funcionar
    // srand(time(NULL));
    //tamanho da array gerada
    // int size = 20;
    // int array1[size];
    // int array2[size];

    // comentar para usar valores aleatorios
    int array1[] = {29728,6199,11752,22374,26560,1008,7477,6004,17271,21564,28602,16064,15579,20587,13383,18338,15897,14595,23682};
    // comentar para usar valores aleatorios
    int array2[] = {5552,949,22407,16726,9484,27049,20646,32098,21720,24630,28947,31819,2255,14829,30938,8066,22255,11712,20362};

    int temp = -1;
    int *pointer_temp = &temp;
    int num1,num2;
    int lenght = sizeof(array1)/sizeof(array1[0]);

    // gerador de números randomicos
    // for (int i = 0; i < size; i++)
    // {
    //     array1[i] = rand();
    //     array2[i] = rand() + 3;
    //     printf("%d - 1 %d\t2 %d\n", i, array1[i], array2[i]);
    // }

    for (int i = 0; i < lenght - 1; i++)
    {
        for (int j = 0; j < lenght; j++)
        {
            // Para não fazer comparações redundantes
             if (j <= i)
             {

                if (temp > abs(array1[j] - array1[i]) && i != j)
                {
                    temp = abs(array1[j] - array1[i]);
                    num1 = array1[i];
                    num2 = array1[j];
                    continue;
                }

                if (temp > abs(array2[j] - array2[i]) && i != j)
                {
                    temp = abs(array2[j] - array2[i]);
                    num1 = array2[i];
                    num2 = array2[j];
                    continue;
                }

                comparador(pointer_temp, array2[j], array1[i], &num1, &num2);

                if (i == 0 && j == 0) {
                    temp = abs(array2[j] - array1[i]);
                    num1 = array1[i];
                    num2 = array2[j];
                }

                continue;
            }

            comparador(pointer_temp, array1[j], array1[i], &num1, &num2);
            comparador(pointer_temp, array1[j], array2[i], &num1, &num2);
            comparador(pointer_temp, array2[j], array2[i], &num1, &num2);
        }
    }

    printf("[%d, %d] -> %d", num1, num2, temp);
}
