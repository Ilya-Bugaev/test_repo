#include "binary.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>


// Тест функции bin() для положительных чисел
bool testBinPositive() 
{
    char binary[BITS + 1];
    
    bin(5, binary);
    if (strcmp(binary, "00000101") != 0) {
        return false;
    }
    bin(10, binary);
    if (strcmp(binary, "00001010") != 0) {
        return false;
    }
    
    bin(0, binary);
    if (strcmp(binary, "00000000") != 0) {
        return false;
    }
    
    bin(127, binary);
    if (strcmp(binary, "01111111") != 0) {
        return false;
    }
    
    return true;
}

// Тест функции bin() для отрицательных чисел
bool testBinNegative() 
{
    char binary[BITS + 1];
    
    bin(-1, binary);
    if (strcmp(binary, "11111111") != 0) {
        return false;
    }
    
    bin(-5, binary);
    if (strcmp(binary, "11111011") != 0) {
        return false;
    }
    
    bin(-128, binary);
    if (strcmp(binary, "10000000") != 0) {
        return false;
    }
    
    return true;
}

// Тест функции sumBinary()
bool testSumBinary() 
{
    char bin1[BITS + 1], bin2[BITS + 1], result[BITS + 1];
    
    // Тест 1: 5 + 3 = 8
    strcpy(bin1, "00000101");
    strcpy(bin2, "00000011");
    sumBinary(bin1, bin2, result);
    if (strcmp(result, "00001000") != 0) {
        return false;
    }
    
    // Тест 2: 10 + 10 = 20
    strcpy(bin1, "00001010");
    strcpy(bin2, "00001010");
    sumBinary(bin1, bin2, result);
    if (strcmp(result, "00010100") != 0) {
        return false;
    }
    
    // Тест 3: -1 + 1 = 0
    strcpy(bin1, "11111111");
    strcpy(bin2, "00000001");
    sumBinary(bin1, bin2, result);
    if (strcmp(result, "00000000") != 0) {
        return false;
    }
    
    return true;
}

// Тест функции dec() для положительных чисел
bool testDecPositive() 
{
    if (dec("00000101") != 5) {
        return false;
    }
    if (dec("00001010") != 10) {
        return false;
    }
    if (dec("01111111") != 127) {
        return false;
    }
    if (dec("00000000") != 0) {
        return false;
    }
    
    return true;
}

// Тест функции dec() для отрицательных чисел
bool testDecNegative() 
{
    if (dec("11111111") != -1) {
        return false;
    }
    if (dec("11111011") != -5) {
        return false;
    }
    if (dec("10000000") != -128) {
        return false;
    }
    
    return true;
}

int main(void) 
{
    bool allTestsPassed = true;
    
    // Запускаем все тесты
    if (!testBinPositive()) {
        printf("Test failed: testBinPositive\n");
        allTestsPassed = false;
    }
    
    if (!testBinNegative()) {
        printf("Test failed: testBinNegative\n");
        allTestsPassed = false;
    }
    
    if (!testSumBinary()) {
        printf("Test failed: testSumBinary\n");
        allTestsPassed = false;
    }
    
    if (!testDecPositive()) {
        printf("Test failed: testDecPositive\n");
        allTestsPassed = false;
    }
    
    if (!testDecNegative()) {
        printf("Test failed: testDecNegative\n");
        allTestsPassed = false;
    }
    
    if (allTestsPassed) {
        printf("All tests passed!\n");
        return 0;
    } else {
        return 1;
    }
}