#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
using namespace std;

typedef struct obj {
    struct obj* next;
    int number;
}OBJ;

typedef struct obj* Stack;

#define STACK_EMPTY (0)


void push(Stack* s, int number) {
    OBJ* ptr = new OBJ;

    ptr->number = number;
    ptr->next = *s;
    *s = ptr;
}
//void pop() {
//    if (top == NULL) return;
//    OBJ* ptr = top->next;
//
//    cout << top->data.number << " deleted\n";
//    delete top;
//    top = ptr;
//}
void stackPrint(const Stack* s) {
    OBJ* ptr = new OBJ;


    for (ptr = *s; ptr != 0; ptr = ptr->next) {
        printf("%d ", ptr->number);
    }

    putchar('\n');
}
int stackEmpty(const Stack* s) {
    return (*s == 0);
}

int stackPop(Stack* s)
{
    int ret;
    OBJ* ptr = new OBJ;

    assert(!stackEmpty(s));

    ret = (*s)->number;

    /* patch out first element */
    ptr = *s;
    *s = ptr->next;


    return ret;
}

void task(const Stack* s) {
    OBJ* ptr = new OBJ;


    
}

int main()
{
    srand((unsigned int)time(NULL));
    int n;
    Stack s = STACK_EMPTY;
    Stack q = STACK_EMPTY;
    Stack r = STACK_EMPTY;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int rand_number = -20 + rand() % (80);
        push(&s, rand_number);
    }
    stackPrint(&s);
    cout << endl;

    while (!stackEmpty(&s)) {
        int temp = stackPop(&s);
        if (temp % 7 == 0) {
            push(&q, temp);
        }
        else {
            push(&r, temp);

        }
    }
    stackPrint(&q);
    stackPrint(&r);


    return 0;
}
