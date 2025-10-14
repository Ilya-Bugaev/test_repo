#include "sorting.h"

void quickSort(int arr[], int left, int right)
{
    if (left >= right)
        return;

    int piv = arr[(left + right) / 2]; // опорный элемент (средний элемент массива)
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
    // Рекурсивная сортировка левой части:
    quickSort(arr, left, j);
    // Рекурсивная сортировка правой части:
    quickSort(arr, i, right);
}
