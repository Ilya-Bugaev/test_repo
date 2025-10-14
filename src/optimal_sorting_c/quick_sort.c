#include <stdio.h>

#define SIZE 10

int main()
{
    printf("Enter exactly 100 numbers separated by spaces:\n");
    int arr[SIZE];
    
    
    // Ввод массива с клавиатуры
    for (int i = 0; i < SIZE; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            printf("input error\n");
            return 1;
        }
    }

    quickSort(arr, 0, SIZE - 1);

    for (int i = 0; i < SIZE; i++) {
        printf("%d ", arr[i]);
    }
}