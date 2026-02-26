#include "binary.h"
#include <stdio.h>
#include <string.h>


void bin(int num, char *binary)
{
    unsigned int unum = (unsigned int)num;
    
    for (int i = 0; i < BITS; i++) {
        binary[i] = ((unum >> (BITS - 1 - i)) & 1) + '0';
    }
    binary[BITS] = '\0';   
}

void sumBinary(char *bin1, char *bin2, char *result)
{
    int carry = 0;

    for (int i = BITS - 1; i >= 0; i--) {
        int bit1 = bin1[i] - '0';
        int bit2 = bin2[i] - '0';

        int sum = bit1 + bit2 + carry;
        result[i] = (sum % 2) + '0';
        carry = sum / 2;
    }

    result[BITS] = '\0';
}

int dec(char *binary) {
    if (binary[0] == '1') {
        char inverted[BITS + 1];
        for (int i = 0; i < BITS; i++) {
            inverted[i] = (binary[i] == '0') ? '1' : '0';
        }
        inverted[BITS] = '\0';
        
        char one[BITS + 1];
        for (int i = 0; i < BITS; i++) {
            one[i] = (i == BITS - 1) ? '1' : '0';
        }
        one[BITS] = '\0';
        
        char temp[BITS + 1];
        sumBinary(inverted, one, temp);
        
        int num = 0;
        for (int i = 0; i < BITS; i++) {
            num = (num << 1) | (temp[i] - '0');
        }
        return -num;
    } else {
        int num = 0;
        for (int i = 0; i < BITS; i++) {
            num = (num << 1) | (binary[i] - '0');
        }
        return num;
    }
}

void printBin(char *binary)
{
    size_t length = strlen(binary);
    for (size_t i = 0; i < length; i++) {
        printf("%c", binary[i]);
    }
    printf("\n");
}