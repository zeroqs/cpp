#include <iostream>
#include <clocale>
#include <cstdlib>
#include <string>

#include <windows.h>
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
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");

    string flag;
    string name;
    int avg;
    int type;

    while (true) {
        cout << "Завершить ввод? "; cin >> flag;
        if (flag == "Да") {
            break;
        }
        else {
            cout << "Введите ФИО "; cin >> name;
            cout << "Введите ср.оценку "; cin >> avg;
            cout << "Введите бюджет - 0 , внебюджет - 1 "; cin >> type;

            STUDENT list = { name,avg };
            add_obj(tail, list);
        }
        

    }

  


    show();


    return 0;
}


