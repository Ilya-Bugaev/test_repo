#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


// Структура узла списка
typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct LinkedList {
    Node* head;
    int size;
} LinkedList;

// Функция создания нового узла
Node* createNode(int data)
{
    Node* newNode = malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Ошибка выделения памяти!\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Инициализация списка
void initList(LinkedList* list) 
{
    list->head = NULL;
    list->size = 0;
}

// Проверка на пустоту
bool isEmpty(LinkedList* list) 
{
    return list->head == NULL;
}

// Получение размеров списка
int getSize(LinkedList* list) 
{
    return list->size;
}

// Вставка в начало
void insertHead(LinkedList* list, int data) 
{
    Node* newNode = createNode(data);
    if (newNode == NULL) return;
    
    newNode->next = list->head;
    list->head = newNode;
    list->size++;
}

// Поиск по индексу
int getByIndex(LinkedList* list, int index) 
{
    if (index < 0 || index >= list->size) {
        return -1; // Индекс вне диапазона
    }
    
    Node* current = list->head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    return current->data;
}

// Удаление первого элемента (вспомогательная функция)
void deleteFront(LinkedList* list) {
    if (isEmpty(list)) return;
    
    Node* temp = list->head;
    list->head = list->head->next;
    free(temp);
    list->size--;
}

// Очистка всего списка
void clearList(LinkedList* list) {
    while (!isEmpty(list)) {
        deleteFront(list);
    }
}

bool isPalindrome(LinkedList* list) {
    if (list == NULL || list->size <= 1) {
        return true; 
    }

    int size = list->size;
    int part = size / 2;

    for (int i = 0; i < part; i++) {
        int a = getByIndex(list, i);
        int b = getByIndex(list, size - 1 - i); 

        if (a != b) {
            return false; 
        }
    }
    return true;
}

// Главная функция для работы с пользователем
int main()
{
    int num = 1;
    LinkedList list;
    initList(&list);
    
    printf("Вводите числа (выйти - 0):\n");
    while (num != 0) {
        scanf("%d", &num);
        if (num != 0) {
            insertHead(&list, num);
        }
    }

    bool check = isPalindrome(&list);

    if (check) {
        printf("\nПалиндром\n");
    } else {
        printf("\nНе палиндром\n");
    }

    clearList(&list);
    return 0;
}


// Тест 1: Пустой список - должен быть палиндромом
bool testEmptyList()
{
    LinkedList list;
    initList(&list);
    bool result = isPalindrome(&list);
    clearList(&list);
    return result;
}

// Тест 2: Палиндром нечетной длины
bool testOddPalindrome()
{
    LinkedList list;
    initList(&list);
    // Создаем: 1 2 3 2 1
    insertHead(&list, 1);
    insertHead(&list, 2);
    insertHead(&list, 3);
    insertHead(&list, 2);
    insertHead(&list, 1);
    bool result = isPalindrome(&list);
    clearList(&list);
    return result;
}

// Тест 3: Палиндром четной длины
bool testEvenPalindrome()
{
    LinkedList list;
    initList(&list);
    // Создаем: 1 2 2 1
    insertHead(&list, 1);
    insertHead(&list, 2);
    insertHead(&list, 2);
    insertHead(&list, 1);
    bool result = isPalindrome(&list);
    clearList(&list);
    return result;
}

// Тест 4: Не палиндром
bool testNotPalindrome()
{
    LinkedList list;
    initList(&list);
    // Создаем: 1 2 3 4 5
    insertHead(&list, 1);
    insertHead(&list, 2);
    insertHead(&list, 3);
    insertHead(&list, 4);
    insertHead(&list, 5);
    bool result = !isPalindrome(&list); // Ожидаем false
    clearList(&list);
    return result;
}

