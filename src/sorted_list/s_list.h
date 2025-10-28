#pragma once

// Структура узла односвязного списка
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Структура сортированного списка
typedef struct {
    Node* head;
    int size;
} SortedList;


void initList(SortedList* list);
void resetList(SortedList* list);
void insertValue(SortedList* list, int value);
void deleteValue(SortedList* list, int value);
void printList(SortedList* list);