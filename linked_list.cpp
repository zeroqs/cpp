#include <iostream>
#include <list>
using namespace std;


typedef struct { // Данные в списке
    string name;
    int avg_score;
    bool student_type;
}STUDENT;

typedef struct link_list { // Объект списка
    STUDENT student;
    struct link_list* prev, * next;
} LIST;

LIST* head = NULL, * tail = NULL;

void add_obj(LIST* obj, STUDENT student) {
    LIST* ptr = new LIST;

    ptr->student = student;
    ptr->prev = obj;
    ptr->next = (obj == NULL) ? NULL : obj->next;

    if (obj != NULL) {
        if (obj->next != NULL) obj->next->prev = ptr;
        obj->next = ptr;
    }

    if (ptr->prev == NULL) head = ptr;
    if (ptr->next == NULL) tail = ptr;
}

void show() {
    LIST* c = head;

    while (c != NULL) {
        cout << c->student.name << endl;
        c = c->next;
    }
}


int main()
{
    setlocale(LC_ALL, "rus");


   


    
    STUDENT list = {"Алекс",5,true};

    add_obj(tail, list);

    show();


    return 0; 
}

