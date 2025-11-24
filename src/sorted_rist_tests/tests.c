#include <stdio.h>
#include <stdbool.h>
#include "s_list.h"
#include "tests.h"

bool testEmptyList()
{
    SortedList list;
    initList(&list);
    
    // Проверка пустого списка
    bool test1 = (list.head == NULL && list.size == 0);
    
    // Удаление из пустого списка
    deleteValue(&list, 5);
    bool test2 = (list.head == NULL && list.size == 0);
    
    resetList(&list);
    return test1 && test2;
}

bool testSingleElement()
{
    SortedList list;
    initList(&list);
    
    // Вставка одного элемента
    insertValue(&list, 10);
    bool test1 = (list.head != NULL && list.head->data == 10 && list.size == 1);
    
    // Удаление единственного элемента
    deleteValue(&list, 10);
    bool test2 = (list.head == NULL && list.size == 0);
    
    resetList(&list);
    return test1 && test2;
}

bool testInsertInOrder()
{
    SortedList list;
    initList(&list);
    
    // Вставка в разном порядке, проверка сортировки
    insertValue(&list, 20);
    insertValue(&list, 10);  // Должно встать в начало
    insertValue(&list, 30);  // Должно встать в конец
    insertValue(&list, 15);  // Должно встать в середину
    
    bool test1 = (list.size == 4);
    bool test2 = (list.head->data == 10);
    bool test3 = (list.head->next->data == 15);
    bool test4 = (list.head->next->next->data == 20);
    bool test5 = (list.head->next->next->next->data == 30);
    
    resetList(&list);
    return test1 && test2 && test3 && test4 && test5;
}

bool testDeleteOperations()
{
    SortedList list;
    initList(&list);
    
    // Создаем список: 10 -> 20 -> 30
    insertValue(&list, 20);
    insertValue(&list, 10);
    insertValue(&list, 30);
    
    // Удаление из начала
    deleteValue(&list, 10);
    bool test1 = (list.head->data == 20 && list.size == 2);
    
    // Удаление из конца
    deleteValue(&list, 30);
    bool test2 = (list.head->data == 20 && list.size == 1);
    
    // Удаление несуществующего элемента
    deleteValue(&list, 99);
    bool test3 = (list.head->data == 20 && list.size == 1);
    
    // Удаление последнего элемента
    deleteValue(&list, 20);
    bool test4 = (list.head == NULL && list.size == 0);
    
    resetList(&list);
    return test1 && test2 && test3 && test4;
}

bool testClearList()
{
    SortedList list;
    initList(&list);
    
    // Заполняем список
    for (int i = 0; i < 5; i++) {
        insertValue(&list, i * 10);
    }
    
    // Очищаем
    resetList(&list);
    
    return (list.head == NULL && list.size == 0);
}

bool runAllTests()
{
    return testEmptyList() && testSingleElement() && testInsertInOrder() && testDeleteOperations() && testClearList();
} 
