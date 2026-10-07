#include <iostream>
using namespace std;

int main()
{
    int arr[100] = {10, 20, 30, 40};
    int n = 4;
    int value = 50;

    arr[n] = value;

    n++;
    cout << "Array after insertion: ";

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}