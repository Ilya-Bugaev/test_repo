#pragma once

// Структура узла циклического списка
typedef struct Node {
    int pos;
    struct Node* next;
} Node;

// Структура циклического списка
typedef struct CyclicList{
    Node* head;
    int size;
} CyclicList;


void initList(CyclicList* list, int len);  
void destroyList(CyclicList* list);
void removeWarrior(CyclicList* list, Node* rem, Node* previous);