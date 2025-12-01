#include "double_utils.h"
#include <stdio.h>
#include <stdint.h>


int main() 
{
    double value;
    printf("Enter a number: ");
    scanf("%lf", &value);
    
    char result[256];
    if (formatDoubleAsBinary(value, result, sizeof(result))) {
        printf("Result: %s\n", result);
    } else {
        printf("Error formatting number\n");
    }
    
    return 0;
}