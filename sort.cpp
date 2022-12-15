#include<iostream>
#include <time.h>

using namespace std;

const int nmax = 1000;

void Merg(int arr[], int begin, int end)
{
	int left_array_index = begin,
		mid = begin + (end - begin) / 2,
		right_array_index = mid + 1,
		index_of_result_array = 0,
		result_array[nmax];

	while (left_array_index <= mid && right_array_index <= end) {

		if (arr[left_array_index] <= arr[right_array_index]) {
			result_array[index_of_result_array] = arr[left_array_index]; left_array_index++;
		}
		else {
			result_array[index_of_result_array] = arr[right_array_index]; right_array_index++;
		}
		index_of_result_array++;
	}

	while (left_array_index <= mid) {
		result_array[index_of_result_array] = arr[left_array_index]; left_array_index++; index_of_result_array++;
	}

	while (right_array_index <= end) {
		result_array[index_of_result_array] = arr[right_array_index]; right_array_index++; index_of_result_array++;
	}

	for (left_array_index = 0; left_array_index < index_of_result_array; left_array_index++)
		arr[begin + left_array_index] = result_array[left_array_index];
}

void MergSort(int* arr, int left, int right)
{
	if (left < right) // проверка на одноелементный массив
		if (right - left == 1) // если в массиве два елемента - меняем их местами  
		{ 
			if (arr[right] < arr[left]) {
				swap(arr[left], arr[right]);
			}
		}
		else {
			MergSort(arr, left, left + (right - left) / 2); // левый массив
			MergSort(arr, left + (right - left) / 2 + 1, right); // правый массив
			Merg(arr, left, right);
		}
}



void input(int* initial_array, int& n)
{
	cout << "Введите количество элементов массива ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		initial_array[i] = -20 + rand() % (80);
	}

}
void print(int* initial_array, int n)
{
	for (int i = 0; i < n; i++)
		cout << initial_array[i] << " ";
	cout << "\n";

}

void main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "rus");

	int n, initial_array[nmax];

	input(initial_array, n);

	cout << "Исходный массив:\n";
	print(initial_array, n);

	MergSort(initial_array, 0, n - 1);

	cout << "Отсортированный массив:\n";
	print(initial_array, n);
	system("pause");

}
