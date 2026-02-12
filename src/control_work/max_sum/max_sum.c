#include <stdio.h>


int maxSum(int arr[], int len)
{
    int max = 0;
    for (int i = 0; i < len; i++) {
        int sum = 0;
        int num = arr[i];
        while (num != 0) {
            sum = sum + (num % 10);
            num = num / 10;
        }
        if (sum > max) {
            max = sum;
        }
    }
    return max;
}


int main()
{
    int arr[] = {53, 654, 75, 74, 99, 19, 101};

    int length = sizeof(arr) / sizeof(arr[0]);

    int max = maxSum(arr, length); 
    printf("%d\n", max);
    

    return 0;
}