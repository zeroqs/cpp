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
        int rand_number = -20 + rand() % (80);
        maoStack.push(rand_number);
        std::cout << rand_number << ", ";
    }
    cout << "." << endl;
    Stack newMaoStack(size);
    Stack secondStack(size);
    for(int i = 0;i<size;i++) {
        int el = maoStack.pop();
        if(el%7!=0) {
            newMaoStack.push(el);
        } else if(el%7==0) {
            secondStack.push(el);
        }
    }
    cout << "\n";
    cout << "стек не кратных 7" << endl;
    
    for(int i = 0;i<size;i++) {
        newMaoStack.pop(); 
        std::cout << ", ";
    }
    cout << "\n";
    
      cout << "стек кратных 7" << endl;
    
    for(int i = 0;i<size;i++) {
        secondStack.pop(); 
        std::cout << ", ";
    }


    

    
    return 0;
}
