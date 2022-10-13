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

void del_obj(string del_name) {
    LIST* obj = head; 

    while (obj != NULL) {
        if (obj->student.name == del_name) {
            LIST* temp_next = obj->next;
            LIST* temp_prev = obj->prev;
            cout << "Студент " << obj->student.name << " Удалён " << endl;
            delete obj; 
            if (temp_prev != NULL) temp_prev->next = temp_next;
            else head = temp_next; 
            if (temp_next != NULL) temp_next->prev = temp_prev;
            else tail = temp_prev; 
            break;
        }
         
        obj = obj->next;
        cout << "Студента нет в списке " << endl;
    }
    

    
}

void show() {
    LIST* obj = head;

    while (obj != NULL) {
        cout << obj->student.name << endl;
        obj = obj->next;
    }
}


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");

    bool flag = true;
    string name;
    int avg;
    int type;
    int action; 
    string del_name;

    

    while (flag)
    {
        cout << "=============================" << endl;
        cout << "0 - Выйти " << endl;
        cout << "1 - Добавить студента " << endl;
        cout << "2 - Вывести всех студентов " << endl;
        cout << "3 - Удалить студента " << endl;
        cout << "=============================" << endl;
        cin >> action;
        cout << endl;
        switch (action)
        {
            case 0:
                flag = false;
                break;
            case 1:
            {
                cout << "Введите ФИО ";
                cin.ignore();
                getline(cin, name);

                cout << "Введите ср.оценку "; cin >> avg;
                cout << "Введите бюджет - 0 , внебюджет - 1 "; cin >> type;

                STUDENT list = { name,avg };
                add_obj(tail, list);
                break;
            }
            case 2:
                show();
                cout << '\n';
                break; 
            case 3:
                cout << "ФИО удаляемого студента ";
                cin.ignore();
                getline(cin, del_name);
                del_obj(del_name);
                break;
            default:
                cout << "Всегда" << '\n';
                break;
            }

    }





    return 0;
}
