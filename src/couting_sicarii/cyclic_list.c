#include <stdio.h>
#include <stdlib.h>
#include "c_list.h"

void process(CyclicList* list, int m) {
    if (list->head == NULL || list->size == 0) {
        printf("Круг пуст!\n");
        return;
    }
    
    Node* current = list->head;
    int step = 1;

    //Особый случай: m = 1 - убивают каждого первого
    if (m == 1) {
        while (list->size > 1) {
            // Удаляем текущего воина (первого)
            Node* toRemove = current;
            current = current->next;  // Переходим к следующему перед удалением
            removeWarrior(list, toRemove, NULL);
        }
    } else{
        while (list->size > 1) {
            // Находим воина, ПРЕДШЕСТВУЮЩЕГО жертве
            for (int i = 1; i < m - 1; i++) {
                current = current->next;
            }
            
            // Используем отдельную функцию для удаления
            removeWarrior(list, current->next, current);
            
            // Переходим к следующему воину (после удаленного)
            current = current->next;
        }
    }
}   

int main()
{
    CyclicList list;
    int n;
    int m;
    printf("Введите количество войнов: ");
    scanf("%d", &n);
    printf("Введите m: ");
    scanf("%d", &m);
    initList(&list, n);
    process(&list, m);

    int savePosition = list.head->pos;
    printf("Безопасная позиция:%d\n", savePosition);

    destroyList(&list);

    return 0;
}