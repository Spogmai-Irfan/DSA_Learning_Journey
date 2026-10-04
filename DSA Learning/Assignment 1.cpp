#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace chrono;

// Iterative Varionacci
vector<unsigned long long> CalculateVarionacciIterative(int n)
{
    vector<unsigned long long> series;

    if (n <= 0)
        return series;

    // First value
    series.push_back(2);

    if (n == 1)
        return series;

    // Second value
    series.push_back(2);

    if (n == 2)
        return series;

    // Third value
    series.push_back(3);

    // Calculate remaining values
    for (int i = 3; i < n; i++)
    {
        unsigned long long next =
            series[i - 1] + series[i - 2];

        series.push_back(next);
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
        CalculateVarionacciIterative(n);

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