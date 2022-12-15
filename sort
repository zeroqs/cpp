#include <stdio.h>
#include <stdlib.h>
#include <time.h>


// Объединяем два отсортированных подмассива `arr[low…mid]` и `arr[mid+1…high]`
void Merge(int targer_array[], int array_left[], int array_right[])
{
    
}

// Сортируем массив `arr[low…high]`, используя вспомогательный массив `aux`
void merge_sort(int arr[], int aux[], int low, int high)
{
    // Базовый вариант
    if (high == low) {        // если размер прогона == 1
        return;
    }

    // найти середину
    int mid = (low + ((high - low) >> 1));

    // рекурсивное разделение выполняется на две половины до тех пор, пока размер выполнения не станет == 1,
    // затем объединяем их и возвращаемся вверх по цепочке вызовов

    merge_sort(arr, aux, low, mid);          // разделить/объединить левую половину
    merge_sort(arr, aux, mid + 1, high);     // разделить/объединить правую половину

    Merge(arr, aux, low, mid, high);        // объединить два полупрогона.
}


int main(void)
{
    int n;
    cin >> n;
    srand(time(NULL));
    int* initial_array = new int[n];

    // генерируем случайный ввод целых чисел
    for (int i = 0; i < n; i++) {
        initial_array[i] = -20 + rand() % (80);
    }

    // сортируем массив `arr`, используя вспомогательный массив `aux`
    merge_sort(initial_array, aux, 0, N - 1);

    for (int i = 0; i < N; i++) {
        printf("%d ", initial_array[i]);
    }

    return 0;
}
