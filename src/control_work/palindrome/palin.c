#include <stdio.h>
#include <string.h>

int bin(int num)
{
    int bin = 0;
    int k = 1;

    while (num)
    {
        bin += (num % 2) * k;
        k *= 10;
        num /= 2;
    }

    return bin;
}

int pal(char str[], int len)
{
    char str2[100];
    int c = 0;
    for (int i = len - 1; i >= 0; i--) {
        str2[c] = str[i];
        c++;
    }
    str2[c] = '\0';
    if (strcmp(str, str2) == 0) {
        return 1;
    }
    return 0;
}

int is_decimal_palindrome(int num)
{
    char str[100];
    snprintf(str, sizeof str, "%d", num);
    int len = strlen(str);
    return pal(str, len);
}

int main() 
{
    int n;
    scanf("%d", &n);
    
    for (int i = 1; i <= n; i++) {
        int decimal_pal = is_decimal_palindrome(i);
        
        int binary = bin(i);
        char bin_str[100];
        snprintf(bin_str, sizeof bin_str, "%d", binary);
        int bin_len = strlen(bin_str);
        int binary_pal = pal(bin_str, bin_len);
        
        if (decimal_pal && binary_pal) {
            printf("%d\n", i);
        }
    }
    
    return 0;
}