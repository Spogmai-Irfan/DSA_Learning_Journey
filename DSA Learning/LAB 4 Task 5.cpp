#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;
using namespace chrono;

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

void calculateTime(int N)
{
    float* arr1 = InitArray(N);
    float* arr2 = new float[N];

    for (int i = 0; i < N; i++)
    {
        arr2[i] = arr1[i];
    }

    auto start1 = high_resolution_clock::now();

    bubbleSort(arr1, N);

    auto end1 = high_resolution_clock::now();

    auto bubbleTime =
        duration_cast<nanoseconds>(end1 - start1).count();

    // Insertion Sort time
    auto start2 = high_resolution_clock::now();

    insertionSort(arr2, N);

    auto end2 = high_resolution_clock::now();

    auto insertionTime =
        duration_cast<nanoseconds>(end2 - start2).count();

    cout << "\nN = " << N << endl;
    cout << "Bubble Sort Execution Time: "
         << bubbleTime << " ns" << endl;

    cout << "Insertion Sort Execution Time: "
         << insertionTime << " ns" << endl;

    delete[] arr1;
    delete[] arr2;
}

int main()
{
    srand(time(0));

    cout << "Execution Time of Sorting Algorithms" << endl;
    
    calculateTime(10);
    calculateTime(100);
    calculateTime(1000);

    return 0;
}