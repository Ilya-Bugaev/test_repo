#include <stdio.h>

void quickSort(int arr[], int left, int right)
{
    if (left >= right)
        return;

    int piv = arr[(left + right) / 2];
    int i = left, j = right;


    while (i <= j) {
        while (arr[i] < piv)
            i++;
        while (arr[j] > piv)
            j--;

        if (i <= j) {
            int tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
    }
    quickSort(arr, left, j);
    quickSort(arr, i, right);
}

void printWithoutPair(int nums[], int s)
{
    for (int i = 0; i < s - 1; i++) {
        if (nums[i] + 1 != nums[i + 1]) {
            printf("%d ", nums[i]);
        }
    }
    printf("%d\n", nums[s - 1]);

}


int main()
{
    int num = 1;
    int nums[100000];
    int s = 0;
    printf("Введите числа:\n");
    while (num != 0) {
        scanf("%d", &num);
        if (num != 0) {
            nums[s] = num;
            s++;
        }
    }

    quickSort(nums, 0, s - 1);

    printWithoutPair(nums, s);


    return 0;
}