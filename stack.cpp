#include <iostream>
using namespace std;

typedef struct {
    int number;
}DATA;

typedef struct obj{
    DATA data; 
    struct obj* next;
}OBJ;

OBJ* top = NULL;

OBJ* push(DATA obj) {
    OBJ* ptr = new OBJ; 

    ptr->data = obj;
    ptr->next = top;

    top = ptr;
    return ptr;
}
void pop() {
    if (top == NULL) return;
    OBJ* ptr = top->next;

    cout << top->data.number << " deleted\n";
    delete top;
    top = ptr;
}

int main()
{
    

    return 0;
}
