#include <stdio.h>
#include <string.h>
#include "stack.h"

int main() {
    Stack s;
    init_stack(&s);

    char str[1000];
    printf("Введите строку");
    scanf("%999s", str);
    int length = strlen(str);
    
    for (int i = 0; i < length; i++) {
        // Если символ - открывающая скобка, добавляем в стек
        if ((str[i] == '[') || (str[i] == '(') || (str[i] == '{')) { // Проверка 1: стек не должен быть пуст
            push(&s, str[i]);;
        } else if (is_empty(&s)) {
            printf("Скобки несбалансиррованы");
            break;
        } else if ((str[i] == ']' && peek(&s) == '[') || (str[i] == ')' && peek(&s) == '(') || (str[i] == '}' && peek(&s) == '{')) { // Проверка 2: тип скобок должен совпадать
            pop(&s);
        } else {
            printf("Скобки несбалансированы");
            break;
        }
        if ((i == length - 1) && is_empty) {
            printf("Скобки сбалансированы");
        }
    }
    
    return 0;
}