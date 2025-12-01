#include "binary.h"
#include <stdio.h>


int main()
{
    char bin1[BITS + 1];
    char bin2[BITS + 1];
    int num1, num2;
    printf("Ведите два числа: ");
    scanf("%d%d", &num1, &num2);

    bin(num1, bin1);
    bin(num2, bin2);
    printf("Первое число: ");
    printBin(bin1);
    printf("Второе число: ");
    printBin(bin2);

    char resBin[BITS + 1];
    sumBinary(bin1, bin2, resBin);
    printf("Сумма: ");
    printBin(resBin);

    int result = dec(resBin);

    printf("Сумма в десятичной записи: ");
    printf("%d\n", result);

    return 0;
}