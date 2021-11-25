// Lab6.4.1.cpp
// IT-12, Fihura Taras

#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

void input(float* a, const int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << "a[" << i << "] = ";
        cin >> a[i];
    }
    cout << endl;
}

int findMax(float* a, const int size) {
    int maxIndex = 0;
    for (int i = 1; i < size; i++)
    {
        if (fabs(a[maxIndex]) < fabs(a[i]))
        {
            maxIndex = i;
        }
    }
    return maxIndex;
}

int findFirstPositive(float* a, const int size) {
    for (int i = 0; i < size; i++)
    {
        if (a[i] > 0) {
            return i;
        }
    }
    return -1;
}

float calculateSum(float* a, const int size, int from) {
    float sum = 0;
    for (int i = from; i < size; i++)
    {
        sum += a[i];
    }
    return sum;
}

void print(float* a, const int size)
{
    for (int i = 0; i < size; i++)
        cout << setw(4) << a[i];
    cout << endl;
}

void sortByInterval(float* a, const int size, int low, int high) {
    float temp;
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (a[j] < low || a[j] > high) {
                print(a, size);

                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                print(a, size);
                cout << endl;
            }
        }
    }
}

int main()
{
    const int n = 5;
    float a[n];
    input(a, n);

    cout << "max index is " << findMax(a, n) << endl;

    int positiveIndex = findFirstPositive(a, n);
    if (positiveIndex < 0)
    {
        cout << "array contains only negative numbers" << endl;
    }
    else
    {
        cout << "sum is " << calculateSum(a, n, positiveIndex) << endl;
    }

    sortByInterval(a, n, 0, 5);
    print(a, n);

    return 0;
}