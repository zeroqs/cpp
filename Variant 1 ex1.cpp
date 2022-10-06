#include <iostream>

int maxIndex(int array[],int len)
{
    using namespace std;
    int maxIndex = 0; 
    for (int i = 0; i < len; i++)
        if (array[i] > array[maxIndex]) {
            maxIndex = i;
        }
    return maxIndex;
}
int minIndex(int array[], int len)
{
    using namespace std;
    int minIndex = 0;
    for (int i = 0; i < len; i++)
        if (array[i] < array[minIndex]) {
            minIndex = i;
        }
    return minIndex;
}

int max(int first, int second) {
    if (first > second) {
        return first;
    }
    else {
        return second;
    }
}
int min(int first, int second) {
    if (first < second) {
        return first;
    }
    else {
        return second;
    }
}

int multiply(int min, int max,int array[]) {
    using namespace std;
    int res = 1;
    for (; min < max; min++) {
        res *= array[min];
    }
    return res;
}

int negativeSum(int array[], int len) {
    int negativeResult = 0;
    for (int i = 0; i < len; i++)
    {
        if (array[i] < 0) {
            negativeResult += array[i];
        }
    }
    return negativeResult;
}

void sort(int array[],int len) {
    int temp;
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = 0; j < len - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                temp = array[j + 1];
                array[j + 1] = array[j];
                array[j] = temp;
            }
        }
    }
}

int main()
{
    using namespace std;
    int len;
    cin >> len;
    int array[100];
    for (int i = 0; i < len; i++) {
        cin >> array[i];
    }

    int maxIndexArray = maxIndex(array, len);
    int minIndexArray = minIndex(array, len);
    int negativeResult = negativeSum(array, len);
    int minInt = min(maxIndexArray, minIndexArray) + 1;
    int maxInt = max(maxIndexArray, minIndexArray);
    cout << multiply(minInt, maxInt, array) << '\n';
    cout << negativeResult << '\n';
    sort(array, len); 
    for (int i = 0; i < len; i++)
    {
        cout << array[i] << '\n';
    }
    return 0; 
}

