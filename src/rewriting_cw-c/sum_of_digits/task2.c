#include <stdio.h>
#include <stdbool.h>

bool comparingSum(unsigned int a, unsigned int b)
{
    if (a >= 1000000000 || b >= 1000000000) {
        printf("Числа должны быть меньше миллиарда\n");
        return 1;
    }
    
    int countA = 0, countB = 0;
    unsigned int tempA = a, tempB = b;
    
    while (tempA) {
        countA += tempA & 1;
        tempA >>= 1;
    }
    
    while (tempB) {
        countB += tempB & 1;
        tempB >>= 1;
    }
    

    if (countA >= countB) {
        return true;
    }
    else {
        return false;
    }


}

int main() {
    unsigned int a, b;
    
    printf("Введите два числа: ");
    scanf("%u %u", &a, &b);
    
    if (comparingSum) {
        printf("%u\n", a);
    } else {
        printf("%u\n", b);
    }

    
    return 0;
}



// Тест 1: Оба числа равны 0
bool testZeroNumbers() {
    return comparingSum(0, 0) == true;
}

// Тест 2: Первое число имеет больше единиц
bool testFirstHasMoreOnes() {
    return comparingSum(7, 8) == true;
}

// Тест 3: Второе число имеет больше единиц
bool testSecondHasMoreOnes() {
    return comparingSum(1, 3) == false;
}

// Тест 4: Числа с одинаковым количеством единиц
bool testEqualOnes() {
    return comparingSum(5, 10) == true;
}
