#include <iostream>
using namespace std;

void bubbleSort(float arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            // For descending order
            if (arr[j] < arr[j + 1])
            {
                float temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    float arr[] = {45.5, 12.2, 78.4, 23.1, 90.6};
    int n = 5;

    bubbleSort(arr, n);

    cout << "Array after Bubble Sort (Descending): " << endl;

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}