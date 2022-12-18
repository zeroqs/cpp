#include <iostream>

using namespace std;

struct node {

    node* next;

    int info;

};

void push(node* next, node* End) {

    node* el = new node;

    cout << "Введите элемент очереди:";

    cin >> el->info;

    el->next = NULL;

    End->next = el;

    End = el;

}

void pop(node* el, node* Begin) {

    el = Begin;

    Begin = Begin->next;

    delete el;

}

void peek(node* el) {

    cout << "Значение в начале очереди: ";

    cout << el->info << endl;

}

void queue_List(node* Begin) {

    node* current_element = Begin;

    cout << "Элементы очереди: ";

    while (current_element) {

        cout << current_element->info << " ";

        current_element = current_element->next;

    }

    cout << endl;

}

void isEmpty(node* queue) {

    if (queue == NULL)

        cout << "Очередь пуста!" << endl;

    else

        cout << "Очередь имеет элементы" << endl;

}

int main()
{
    setlocale(LC_ALL, "Russian");

    int k = 1;

    cout << "Создание очереди. Пожалуйста, введите первый элемент очереди:" << endl;

    node* Begin, * End;

    node* el = new node;

    cin >> el->info;

    el->next = NULL;

    Begin = End = el;

    while (k) {

        cout << "1 - добавление элемента в конец очереди\n2 - удаление элемента из начала очереди\n3 - функция определения значения в начале очереди\n4 - функция вывода элементов очереди на экран\n5 - функция определения пуста очередь или нет\n" << "0 - выход" << endl;

        cin >> k;

        if (k == 0)

            return 0;

        if (k == 1)

            push(el, End);

        if (k == 2)

            pop(el, Begin);

        if (k == 3)

            peek(Begin);

        if (k == 4)

            queue_List(Begin);

        if (k == 5)

            isEmpty(el);

    }

    cout << endl;

    system("pause");

    return 0;
}
