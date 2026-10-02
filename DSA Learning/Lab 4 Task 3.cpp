#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

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

    cout << "Random Array:" << endl;

    for (int i = 0; i < N; i++)
    {
        cout << arr[i] << " ";
    }

    delete[] arr;

    return 0;
}