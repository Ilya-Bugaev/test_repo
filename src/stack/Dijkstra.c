#include <stdio.h>
#include <string.h>
#include "stack.h"

int main()
{
    Stack st;
    init_stack(&st);

    char str[1000];
    printf("Введите выражение:");
    scanf("%999s", str);
    char output[1000];
    int c = 0;
    int length = strlen(str);
    char digits[] = "1234567890";

    for (int i = 0; i < length; i++) {
        char sym = str[i];
        //Если символ - цифра, добавляем его непосредственно в выход
        if (strchr(digits, sym)) {
            //Выталкиваем из стека все операторы * и /, которые имеют равный приоритет
            output[c] = sym;
            c++;
        }
        if (sym == '/' || sym == '*') {
            while (!is_empty(&st) && (peek(&st) == '*' || peek(&st) == '/')) {
                output[c] = pop(&st);
                c++;
            }
            push(&st, sym);
        }
        if (sym == '+' || sym == '-') {
            while (!is_empty(&st) && peek(&st) != '(') {
                output[c] = pop(&st);
                c++;
            }
            push(&st, sym);
        }
        //Если символ - открывающая скобка, помещаем её в стек
        if (sym == '(') {
            push(&st, sym);
        }
        if (sym == ')') {
            while (!is_empty(&st) && peek(&st) != '(') {
                output[c] = pop(&st);
                c++;
            }
            pop(&st);
        }
    }
    
    //После обработки всей строки выталкиваем все оставшиеся операторы из стека
    while (!is_empty(&st)) {
        output[c] = pop(&st);
        c++;
    }

    for (int i = 0; i <= c; i++) {
        printf("%c", output[i]);
    }

    return 0;
}