#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void bubbleSort(float arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] < arr[j + 1])
            {
                float temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void insertionSort(float arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        float key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] < key)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

float* InitArray(int N)
{
    float* arr = new float[N];

    for (int i = 0; i < N; i++)
    {
        arr[i] = (float)rand() / RAND_MAX * 1000;
    }

    return arr;
}

int main()
{
    srand(time(0));

    int N = 10;

    float* arr = InitArray(N);

    cout << "Original Array:" << endl;

    for (int i = 0; i < N; i++)
    {
        cout << arr[i] << " ";
    }

    bubbleSort(arr, N);

    cout << "\n\nAfter Bubble Sort:" << endl;

    for (int i = 0; i < N; i++)
    {
        cout << arr[i] << " ";
    }

    float* arr2 = InitArray(N);

    cout << "\n\nNew Original Array:" << endl;

    for (int i = 0; i < N; i++)
    {
        cout << arr2[i] << " ";
    }

    insertionSort(arr2, N);

    cout << "\n\nAfter Insertion Sort:" << endl;

    for (int i = 0; i < N; i++)
    {
        cout << arr2[i] << " ";
    }

    delete[] arr;
    delete[] arr2;

    return 0;
}