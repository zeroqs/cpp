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


    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
            array[i][j] = rand() % 10 -5;
    }

    cout << endl;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
            cout << array[i][j] << ' ';
        cout << endl;

    }
    bool flag = false;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
            if (array[i][j] == -3) flag = true;

    }
    cout << flag;

    return 0; 
}

