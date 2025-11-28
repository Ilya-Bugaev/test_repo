#include <stdio.h>
#include "s_list.h"


int main()
{
    SortedList list;
    int choice = 1, value;
    initList(&list);

    while (choice != 0) {
        printf("0 – выйти\n1 – добавить значение в сортированный список\n2 – удалить значение из списка\n3 – распечатать список\n");
        scanf("%d", &choice);
        
        if (choice == 1) {
            printf("Введите значение: ");
            scanf("%d", &value);
            insertValue(&list, value);
        } else if (choice == 2) {
            printf("Введите значение: ");
            scanf("%d", &value);
            deleteValue(&list, value);
        } else if (choice == 3) {
            printList(&list);
        }
    }
    
    resetList(&list);

    return 0;
}