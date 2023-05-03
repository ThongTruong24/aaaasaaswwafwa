/*
 * File: creat_stack.c
 * Author: Thong Truong
 * Date: 02/01/2003
 * Description: Create stack with addition and deletion function
 */

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>


#define LENGTH 5

typedef struct stack {
    uint8_t data[LENGTH];
    int8_t top;
} stack;

void initStack (stack *stack) {
    stack->top = -1;

}

bool fullStack (stack *stack) {
    return stack->top == LENGTH - 1;
}

bool emptyStack (stack *stack) {
    return stack->top == -1;
}

void push (stack *stack, uint8_t data) {

    if (fullStack(stack)) 
        printf("Stack was full !\n");
    else 
        stack->data[++(stack->top)] = data;
    
}

void pop (stack *stack) {

    if (emptyStack(stack)) 
        printf("Stack was empty !\n");
    else (stack->top)--;

}

void print(stack stack) {

    if (emptyStack(&stack)) 
        printf("Don't have data, Stack was empty !!!");
    else
        printf("Top value: %d\n", stack.data[stack.top]);

}

int main() {

    stack Stack;

    initStack (&Stack);

    push (&Stack, 1);
    push (&Stack, 8);
    push (&Stack, 6);
    push (&Stack, 5);
    push (&Stack, 2);
    //push (&Stack, 2);
    print (Stack);

    pop (&Stack);
    pop (&Stack);
    pop (&Stack);
    pop (&Stack);
    //pop (&Stack);
    print (Stack);

    //printPop(&Stack);
    // Sử dụng setjum để ko ngừng thao tác với top khi full hay rổng stack (tùy vào trường hợp sử dụng)
    // Ứng dụng trong embedded
    // for (int i = 0; i < 5; i++) {
    //     uint8_t *ptr = (uint8_t *)malloc(4);
    //     push(&Stack, ptr);
    // }

    // while(!emptyStack) {
    //     uint8_t *ptr = (uint8_t *)pop(&Stack);
    //     free(ptr);
    // }
}