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

int main()
{
    using namespace std;
    int array[16] = { 5, -12, -12, 9, 10, 0, -9, -12, -1, 23, 65, 64, 11, 43, 39, -15 };
    int len = sizeof(array) / sizeof(array[0]);

    int maxIndexArray = maxIndex(array, len);
    int minIndexArray = minIndex(array, len);
    int negativeResult = negativeSum(array, len);
    cout << multiply((min(maxIndexArray, minIndexArray)+1), max(maxIndexArray, minIndexArray), array) << '\n';
    cout << negativeResult << '\n';
    return 0; 
}

