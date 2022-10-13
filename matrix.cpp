#include <iostream>
#include <list>
#include <time.h>
#include <stdlib.h>
using namespace std;




int main()
{
    setlocale(LC_ALL, "rus");
    srand(time(NULL));

    const int N = 3;
    const int M = 6;

    int array[N][M];

    // Ввод матрицы
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++) {
            array[i][j] = rand() % 50 - 10;
        }
    } 

    // Вывод матрицы
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++) {
            cout << array[i][j] << ' ';
        }
        cout << endl;

    } 

    cout << endl;
    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        int temp_sum = 0;
        bool flag = false;

        for (int j = 0; j < M; j++) 
        {
            temp_sum += array[i][j];
            if (array[i][j] < 0) {
                flag = true;
            }

        }
        if (flag) {
            cout << "Строчка " << i + 1 << " " << temp_sum << endl;
        }


    }
    

    return 0; 
}

