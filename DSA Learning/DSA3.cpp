#include <iostream>
using namespace std;

int main()
{
    int arr[100] = {10, 20, 30, 40};
    int n = 4;

    int value = 25;
    int position = 3;
    for (int i = n; i >= position; i--)
    {
        arr[i] = arr[i - 1];
    }

    arr[position - 1] = value;

    n++;
    cout << "Array after insertion: ";

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}