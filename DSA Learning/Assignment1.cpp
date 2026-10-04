#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace chrono;

// Recursive function
void CalculateVarionacciRecursive(
    int current,
    int n,
    unsigned long long a,
    unsigned long long b,
    vector<unsigned long long>& series)
{
    // Stop when we have n values
    if (current >= n)
        return;

    unsigned long long next = a + b;

    series.push_back(next);

    CalculateVarionacciRecursive(
        current + 1,
        n,
        b,
        next,
        series
    );
}

vector<unsigned long long> GenerateRecursive(int n)
{
    vector<unsigned long long> series;

    if (n <= 0)
        return series;

    // According to the assignment's given sequence
    if (n >= 1)
        series.push_back(2);

    if (n >= 2)
        series.push_back(2);

    if (n >= 3)
        series.push_back(3);

    if (n >= 4)
        series.push_back(4);

    if (n > 4)
    {
        CalculateVarionacciRecursive(
            4,
            n,
            3,
            4,
            series
        );
    }

    return series;
}

int main()
{
    int n;

    cout << "Enter number of values: ";
    cin >> n;

    auto start = high_resolution_clock::now();

    vector<unsigned long long> result =
        GenerateRecursive(n);

    auto end = high_resolution_clock::now();

    cout << "\nVarionacci Series:\n";

    for (unsigned long long value : result)
    {
        cout << value << " ";
    }

    cout << "\n";

    auto duration =
        duration_cast<microseconds>(end - start);

    cout << "\nLatency: "
         << duration.count()
         << " microseconds\n";

    cout << "Latency: "
         << duration.count() / 1000.0
         << " milliseconds\n";

    return 0;
}