#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{

    // descomentar para o rand funcionar
    //  srand(time(NULL));
    int tamanho = 10;

    int array1[] = {1, 3, 4, 5, 2, 6, 7, 70, 100, 92, 20};
    int array2[] = {123, 1241, 4532, 342, 134, 1233, 43, 70, 70, 300};
    int temp = 123412344;

    // gerador de números randomicos
    // for (int i = 0; i < tamanho; i++)
    // {
    //     array1[i] = rand();
    //     array2[i] = rand();
    //     printf("%d - 1 %d  2%d \n",i, array1[i], array2[i])   ;
    // }

    for (int i = 0; i < tamanho - 1; i++)
    {
        for (int j = 0; j < tamanho; j++)
        {
            if (j <= i)
            {

                if (i == 0 && j == 0)
                {
                    temp = abs(array2[j] - array1[i]);
                    continue;
                }

                if (temp > abs(array2[j] - array1[i]))
                {
                    temp = abs(array2[j] - array1[i]);
                    continue;
                }

                if (temp > abs(array2[j] - array2[i]) && i != j)
                {
                    temp = abs(array2[j] - array2[i]);
                    continue;
                }

                continue;
            }

            if (temp > abs(array1[j] - array1[i]))
            {
                temp = abs(array1[j] - array1[i]);
            }
            else if (temp > abs(array2[j] - array1[i]))
            {
                temp = abs(array2[j] - array1[i]);
            }
            else if (temp > abs(array2[j] - array2[i]))
            {
                temp = abs(array2[j] - array2[i]);
            }
        }
    }

    printf("%d", temp);
}
