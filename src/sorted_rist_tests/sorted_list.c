#include <stdio.h>
#include <string.h>
#include "s_list.h"
#include "tests.h"


int main(int argc, char *argv[])
{
    if (argc == 2 && strcmp(argv[1], "--test") == 0) {
        if (!runAllTests()) {
            printf("Tests failed\n");
            return 1;
        }
        printf("All tests passed!\n");
        return 0;
    } else {    
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
    }
    return 0;
}