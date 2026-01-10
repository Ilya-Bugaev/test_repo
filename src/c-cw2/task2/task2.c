#include <stdio.h>
#include <stdbool.h>

unsigned int findMaxCyclicShift(bool arr[], int n) {
    if (n == 0) return 0;
    
    // Преобразуем массив в число
    unsigned int num = 0;
    for (int i = 0; i < n; i++) {
        num = (num << 1) | arr[i];
    }
    
    unsigned int maxNum = num;
    
    // Для n-битного числа нужно проверить n-1 сдвигов
    for (int i = 1; i < n; i++) {
        // Циклический сдвиг влево на 1 бит
        unsigned int msb = (num >> (n - 1)) & 1;
        num = ((num << 1) & ((1u << n) - 1)) | msb;
        
        if (num > maxNum) {
            maxNum = num;
        }
    }
    
    return maxNum;
}

int main() {
    int n;
    
    printf("Введите длину двоичного числа (N <= 32): ");
    scanf("%d", &n);
    
    if (n <= 0 || n > 32) {
        printf("Некорректная длина массива. Должна быть 1 <= N <= 32\n");
        return 1;
    }
    
    bool binaryArr[32];
    
    printf("Введите %d битов (0 или 1):\n", n);
    for (int i = 0; i < n; i++) {
        int bit;
        scanf("%d", &bit);
        binaryArr[i] = (bit != 0);
    }
    
    unsigned int maxValue = findMaxCyclicShift(binaryArr, n);
    
    printf("Наибольшее число после циклических сдвигов: %u\n", maxValue);
    
    return 0;
}