#include <iostream>
#include <cstdlib>
using namespace std;
 
// создадим стек. как основу используем массив

// Определяем емкость stack по умолчанию
#define SIZE 10
 
// Класс для представления stack
class Stack
{
    int *arr;
    int top;
    int capacity;
 
public:
    Stack(int size = SIZE);         // конструктор
    ~Stack();                       // деструктор
 
    void push(int);
    int pop();
    int peek();

};
 
// Конструктор для инициализации stack
Stack::Stack(int size)
{
    arr = new int[size];
    capacity = size;
    top = -1;
}
 
// Деструктор для освобождения памяти, выделенной для stack
Stack::~Stack() {
    delete[] arr;
}

// Вспомогательная функция для добавления элемента `x` в stack
void Stack::push(int x)
{

    cout << x;
    arr[++top] = x;
}

// Вспомогательная функция для извлечения верхнего элемента из stack
int Stack::pop()
{

    cout << peek();
 
    // уменьшаем размер stack на 1 и (необязательно) возвращаем извлеченный элемент
    return arr[top--];
}


// Вспомогательная функция для возврата верхнего элемента stack
int Stack::peek()
{
    return arr[top];
}


int main()
{
    int size;
    std::cout << "Какова размерность стека? ";
    std::cin >> size;
    Stack maoStack(size);
    cout << "Стек:";
    srand((unsigned int)time(NULL));
    for(int i = 0;i<size;i++) {
        maoStack.push(-20 + rand() % (80));
        std::cout << ", ";
    }
    cout << "." << endl;
    cout << "Теперь удалим из стека элементы" << endl;
    // создадим новый стек, такой же как прошлый, но пустой
    Stack newMaoStack(size);
    Stack secondStack(size);
    for(int i = 0;i<size;i++) {
        int el = maoStack.pop();
        std::cout << " удалено."<< endl;
        if(el%7!=0) {
            std::cout << "В новый стек записали ";
            newMaoStack.push(el);
            std::cout << "."<< endl;
        } else {
            secondStack.push(el);
        }
    }
    cout << "Новый стек" << endl;
    
    for(int i = 0;i<size;i++) {
        newMaoStack.pop(); 
        std::cout << ", ";
    }

    

    
    return 0;
}
