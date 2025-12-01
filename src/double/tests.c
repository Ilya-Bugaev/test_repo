#include "double_utils.h"
#include <stdio.h>
#include <stdbool.h>
#include <string.h>


// Тест для -2.5
bool testMinusTwoPointFive() 
{
    char buffer[100];
    if (!formatDoubleAsBinary(-2.5, buffer, sizeof(buffer))) {
        return false;
    }
    return strcmp(buffer, "-1.25*2^1") == 0;
}

// Тест для 12312.323
bool test12312_323() 
{
    char buffer[100];
    if (!formatDoubleAsBinary(12312.323, buffer, sizeof(buffer))) {
        return false;
    }
    
    if (buffer[0] != '+') return false;
    
    if (strstr(buffer, "1.502969116210937") == NULL) return false;
    
    int len = strlen(buffer);
    if (len < 5) return false;
    return strcmp(buffer + len - 5, "*2^13") == 0;
}

// Тест для 0
bool testZero() 
{
    char buffer[100];
    if (!formatDoubleAsBinary(0.0, buffer, sizeof(buffer))) {
        return false;
    }
    return strcmp(buffer, "+0.0*2^0") == 0;
}

// Тест для 1
bool testOne() 
{
    char buffer[100];
    if (!formatDoubleAsBinary(1.0, buffer, sizeof(buffer))) {
        return false;
    }
    return strcmp(buffer, "+1.0*2^0") == 0;
}

// Тест для -1
bool testMinusOne() 
{
    char buffer[100];
    if (!formatDoubleAsBinary(-1.0, buffer, sizeof(buffer))) {
        return false;
    }
    return strcmp(buffer, "-1.0*2^0") == 0;
}

int main(void) 
{
    if (!testMinusTwoPointFive()) {
        printf("Test for -2.5 failed\n");
        return 1;
    }
    
    if (!test12312_323()) {
        printf("Test for 12312.323 failed\n");
        return 1;
    }
    
    if (!testZero()) {
        printf("Test for 0 failed\n");
        return 1;
    }
    
    if (!testOne()) {
        printf("Test for 1 failed\n");
        return 1;
    }
    
    if (!testMinusOne()) {
        printf("Test for -1 failed\n");
        return 1;
    }
    
    printf("All tests passed!\n");
    return 0;
}