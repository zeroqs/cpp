#include <stdio.h>
#include <stdlib.h>
#include <time.h>


// Объединяем два отсортированных подмассива `arr[low…mid]` и `arr[mid+1…high]`
void Merge(int targer_array[], int array_left[], int array_right[])
{
    int array_left_index = 0;
    int array_right_index = 0;
    int index_of_insert_min_number_in_array = 0; 
    int array_left_len = sizeof(array_left) / sizeof(array_left[0]);
    int array_right_len = sizeof(array_right) / sizeof(array_right[0]);

    while (array_left_index < array_left_len && (array_right_index < array_right_len))
    {   
        if (array_left[array_left_index] <= array_right[array_right_index])
        {
            target_array[index_of_insert_min_number_in_array] = array_left[array_left_index];
            array_left_index++;
        }
        else
        {
            target_array[index_of_insert_min_number_in_array] = array_right[array_right_index];
            array_right_index++;
        }
        index_of_insert_min_number_in_array;
    }
    while (array_left_index < array_left_len)
    {
        target_array[index_of_insert_min_number_in_array] = array_left[array_left_index];
        array_left_index++;
        index_of_insert_min_number_in_array;

    } 
    while (array_right_index < array_right_len)
    {
        target_array[index_of_insert_min_number_in_array] = array_right[array_right_index];
        array_right_index++;
        index_of_insert_min_number_in_array;

    }
}

// Сортируем массив `arr[low…high]`, используя вспомогательный массив `aux`
void merge_sort(int arr[], int aux[], int low, int high)
{
    int array_len = sizeof(array) / sizeof(array[0]);

    if (array_len < 2) {
        return;
    }
    
    int mid = array_len / 2;
    int* left = new int[mid];
    int* right = new int[array_len - mid];

    for (int i = 0; i < mid; i++)
    {
        left[i] = array[i];
    }
    for (int i = mid; i < array_len; i++)
    {
        right[i] = array[i];
    }
    MergeSort(left);
    MergeSort(right);
    Merge(array, left, right);     // объединить два полупрогона.
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
