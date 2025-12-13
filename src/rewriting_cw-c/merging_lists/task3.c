#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int data;
    struct Node* next;
} Node;


typedef struct LinkedList {
    Node* head;
    int size;
} LinkedList;

// Создание нового узла
Node* createNode(int data) {
    Node* newNode = malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Ошибка выделения памяти\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Создание нового списка
LinkedList* createLinkedList() {
    LinkedList* list = malloc(sizeof(LinkedList));
    if (list == NULL) {
        printf("Ошибка выделения памяти\n");
        exit(1);
    }
    list->head = NULL;
    list->size = 0;
    return list;
}

// Добавление в конец
void append(LinkedList* list, int data) {
    Node* newNode = createNode(data);
    
    if (list->head == NULL) {
        list->head = newNode;
    } else {
        Node* current = list->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
    list->size++;
}

// Печать
void printList(LinkedList* list) {
    Node* current = list->head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Освобождение памяти
void freeLinkedList(LinkedList* list) {
    Node* current = list->head;
    Node* next;
    
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    
    free(list);
}

// Вплетение списка
LinkedList* weaveLists(LinkedList* list1, LinkedList* list2) {
    if (list1 == NULL || list1->head == NULL) {
        LinkedList* result = list2;
        if (list1 != NULL) {
            list1->head = NULL;
            list1->size = 0;
            free(list1);
        }
        return result;
    }
    
    if (list2 == NULL || list2->head == NULL) {
        LinkedList* result = list1;
        if (list2 != NULL) {
            list2->head = NULL;
            list2->size = 0;
            free(list2);
        }
        return result;
    }
    
    LinkedList* result = createLinkedList();
    result->head = list1->head;
    result->size = list1->size + list2->size;
    
    Node* current1 = list1->head;
    Node* current2 = list2->head;
    Node* prev = NULL;
    
    while (current1 != NULL && current2 != NULL) {
        Node* temp1 = current1->next;
        Node* temp2 = current2->next;
        
        current1->next = current2;
        
        if (temp1 != NULL) {
            current2->next = temp1;
        }
        
        prev = current2;
        current1 = temp1;
        current2 = temp2;
    }
    
    if (current2 != NULL && prev != NULL) {
        prev->next = current2;
    }
    
    list1->head = NULL;
    list1->size = 0;
    list2->head = NULL;
    list2->size = 0;
    free(list1);
    free(list2);
    
    return result;
}