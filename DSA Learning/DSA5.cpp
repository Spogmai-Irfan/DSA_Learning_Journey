#include <iostream>
using namespace std;

int main()
{
    int arr[10] = {10, 20, 30, 40, 50};
    int n = 5;

    cout << "Before deletion: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    n--;

    cout << "After deletion at tail: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}