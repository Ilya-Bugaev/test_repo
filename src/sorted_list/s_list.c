#include "s_list.h"
#include <stdlib.h>
#include <stdio.h>

// Инициализация списка
void initList(SortedList* list)
{
    list->head = NULL;
    list->size = 0;
}

// Очищение списка
void resetList(SortedList* list)
{
    Node* current = list->head;
    Node* next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    list->head = NULL;
    list->size = 0;
}


// Вставление значения в сортированный список
void insertValue(SortedList* list, int value)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    // Случай 1: список пуст ИЛИ новое значение меньше головы
    if ((list->head == NULL) || (value < list->head->data))  {
        newNode->next = list->head;
        list->head = newNode;
        list->size++;
        printf("Значение %d добавлено в список.\n", value);
        return;
    }

    // Случай 2: вставка в середину или конец списка
    Node* current = list->head;
    while (current->next != NULL && current->next->data < value) {
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
    list->size++;
    printf("Значение %d добавлено в список.\n", value);
}

// Удаление значения из сортированного списка
void deleteValue(SortedList *list, int value)
{
    // Проверка на пустой список
    if (list->head == NULL) {
        printf("Список пуст.\n");
        return;
    }

    // Случай 1: значение - голова списка
    if (list->head->data == value) {
        Node* temp = list->head;
        list->head = list->head->next;
        free(temp);
        list->size--;
        printf("Значение %d удалено.\n", value);
        return;
    }

    // Случай 2: поиск значения в середине или конце списка
    Node* current = list->head;
    while (current->next != NULL && current->next->data != value) {
        current = current->next;
    }
    if (current->next == NULL) {
        printf("Значения %d нет в списке.\n", value);
        return;
    }
    
    Node* temp = current->next;
    current->next = temp->next;
    free(temp);
    list->size--;
    printf("Значение %d удалено.\n", value);
}

// Вывод содержимого списка
void printList(SortedList *list)
{
    if (list->head == NULL){
        printf("Список пуст.\n");
        return;
    }
    Node* current = list->head;
    while (current != NULL) {
        printf("%d", current->data);
        if (current->next != NULL)
            printf(", ");
        else
            printf("\n");
        current = current->next;
        
    }
}