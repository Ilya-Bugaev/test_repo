#include <stdlib.h>
#include <stdio.h>
#include "c_list.h"

// Инициализация циклического списка заданной длины
void initList(CyclicList* list, int len)
{
    if (len < 1) {
        printf("Длина должна быть больше 0.");
        return;
    }
    
    // Создание первого узла (головы списка)
    list->head = (Node*)malloc(sizeof(Node));
    list->head->pos = 1;
    list->size = len;

    // Создание остальных узлов списка
    Node* current = list->head;
    for (int i = 2; i <= len; i++) {
        current->next = (Node*)malloc(sizeof(Node));
        current = current->next;
        current->pos = i;
    }

    // Замыкание списка в кольцо
    current->next = list->head;
}

// Уничтожение списка и освобождение памяти
void destroyList(CyclicList* list)
{
    if (list->head == NULL) return;
    
    // Поиск последнего узла в циклическом списке
    Node* last = list->head;
    while (last->next != list->head) {
        last = last->next;
    }
    last->next = NULL;
    
    // Последовательное удаление всех узлов списка
    Node* current = list->head;
    while (current != NULL) {
        Node* next = current->next;
        free(current);
        current = next;
    }
    
    list->head = NULL;
    list->size = 0;
}

// Удаление указанного война
void removeWarrior(CyclicList* list, Node* rem, Node* previous)
{
    if (list->size == 0) {
        printf("Круг пуст");
        return;
    }

    //Особый случай: удаляем единственного воина
    if (list->size == 1) {
        free(list->head);
        list->head = NULL;
        list->size = 0;
        return;
    }

    if (rem == list->head) {
        list->head = rem->next;
    }

    if (previous != NULL) {
        previous->next = rem->next;
    } else {
        Node* temp = list->head;
        while (temp->next != rem) {
            temp = temp->next;
        }
        temp->next = rem->next;
    }
    free(rem);
    list->size--;
}