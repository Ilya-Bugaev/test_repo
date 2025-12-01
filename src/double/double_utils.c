#include "double_utils.h"
#include <stdio.h>
#include <stdint.h>
#include <string.h>


typedef union 
{
    double value;
    uint64_t bits;
} DoubleUnion;

bool formatDoubleAsBinary(double value, char* buffer, int bufferSize)
{
    if (bufferSize < 10) return false;
    
    DoubleUnion du;
    du.value = value;

    uint64_t bits = du.bits;
    
    int sign = (bits >> 63) & 1;
    int exponent = ((bits >> 52) & 0x7FF) - 1023;
    uint64_t mantissaBits = bits & 0xFFFFFFFFFFFFF;
    
    if (exponent == -1023) {
        if (mantissaBits == 0) {
            snprintf(buffer, bufferSize, "%c0.0*2^0", sign ? '-' : '+');
            return true;
        } else {
            exponent = -1022;
        }
    } else if (exponent == 1024) {
        if (mantissaBits == 0) {
            snprintf(buffer, bufferSize, "%cInfinity", sign ? '-' : '+');
        } else {
            snprintf(buffer, bufferSize, "NaN");
        }
        return true;
    } else {
        mantissaBits |= (1ULL << 52);
    }

    char mantissaStr[64] = {0};
    int pos = 0;
    
    mantissaStr[pos++] = '1';
    mantissaStr[pos++] = '.';
    
    uint64_t fraction = mantissaBits & ((1ULL << 52) - 1);
    
    for (int i = 0; i < 20 && (fraction != 0 || i == 0); i++) {
        fraction *= 10;
        uint64_t digit = fraction >> 52;
        mantissaStr[pos++] = '0' + (char)digit;
        fraction &= (1ULL << 52) - 1;
    }
    mantissaStr[pos] = '\0';

    snprintf(buffer, bufferSize, "%c%s*2^%d", 
             sign ? '-' : '+', mantissaStr, exponent);
    return true;
} 
