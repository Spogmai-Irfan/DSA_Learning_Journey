#include <iostream>
using namespace std;

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

int main()
{
    float arr[] = {45.5, 12.2, 78.4, 23.1, 90.6};
    int n = 5;

    insertionSort(arr, n);

    cout << "Array after Insertion Sort (Descending): " << endl;

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}