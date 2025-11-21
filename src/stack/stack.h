#pragma once

// Максимальный размер стека
#define MAX_SIZE 1000

// Структура стека
typedef struct {
    char data[MAX_SIZE]; 
    int top;              
} Stack;


void init_stack(Stack* s);

void push(Stack* s, char c);

char pop(Stack* s);

char peek(Stack* s);

int is_empty(Stack* s);

int is_full(Stack* s);