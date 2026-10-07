#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <iomanip>
#include <algorithm>

using namespace std;
using namespace chrono;

// ------------------------------------------------------------
// FUNCTION 1: Add two large numbers
// ------------------------------------------------------------
// We use strings so that the program can calculate 300 values
// without integer overflow.
string addBigNumbers(const string& a, const string& b)
{
    string result;

    int i = static_cast<int>(a.size()) - 1;
    int j = static_cast<int>(b.size()) - 1;

    int carry = 0;

    while (i >= 0 || j >= 0 || carry)
    {
        int sum = carry;

        if (i >= 0)
        {
            sum += a[i] - '0';
            i--;
        }

        if (j >= 0)
        {
            sum += b[j] - '0';
            j--;
        }

        result.push_back(char('0' + (sum % 10)));

        carry = sum / 10;
    }

    reverse(result.begin(), result.end());

    return result;
}


// ============================================================
// ITERATIVE ALGORITHM
// ============================================================

vector<string> calculateVarionacciIterative(int n)
{
    vector<string> series;

    // If user enters 0 or negative number
    if (n <= 0)
    {
        return series;
    }

    // First three fixed values
    series.push_back("2");

    if (n == 1)
    {
        return series;
    }

    series.push_back("2");

    if (n == 2)
    {
        return series;
    }

    series.push_back("3");

    if (n == 3)
    {
        return series;
    }

    // According to the sequence given in the assignment:
    //
    // 2, 2, 3, 4, 5, 7, 9, 12, 16, 21, 28...
    //
    // Starting from the 4th value:
    // next = value two positions before
    //        + value three positions before
    //
    // Example:
    // 4 = 2 + 2
    // 5 = 3 + 2
    // 7 = 4 + 3
    // 9 = 5 + 4

    for (int i = 3; i < n; i++)
    {
        string next =
            addBigNumbers(series[i - 2], series[i - 3]);

        series.push_back(next);
    }

    return series;
}


// ============================================================
// RECURSIVE HELPER FUNCTION
// ============================================================

void recursiveHelper(int n, vector<string>& series)
{
    // Base condition
    if (static_cast<int>(series.size()) >= n)
    {
        return;
    }

    int i = static_cast<int>(series.size());

    // Same formula used by the iterative algorithm
    string next =
        addBigNumbers(series[i - 2], series[i - 3]);

    series.push_back(next);

    // Recursive call
    recursiveHelper(n, series);
}


// ============================================================
// RECURSIVE ALGORITHM
// ============================================================

vector<string> calculateVarionacciRecursive(int n)
{
    vector<string> series;

    if (n <= 0)
    {
        return series;
    }

    // First value
    series.push_back("2");

    if (n == 1)
    {
        return series;
    }

    // Second value
    series.push_back("2");

    if (n == 2)
    {
        return series;
    }

    // Third value
    series.push_back("3");

    if (n == 3)
    {
        return series;
    }

    // Start recursion
    recursiveHelper(n, series);

    return series;
}


// ============================================================
// FUNCTION TO PRINT COMPLETE SERIES
// ============================================================

void printSeries(const vector<string>& series)
{
    for (size_t i = 0; i < series.size(); i++)
    {
        cout << series[i];

        if (i + 1 < series.size())
        {
            cout << ", ";
        }
    }

    cout << endl;
}


// ============================================================
// FUNCTION TO PRINT LARGE OUTPUT NEATLY
// ============================================================

void printPreview(const vector<string>& series)
{
    const size_t preview = 15;

    // If series is small, print everything
    if (series.size() <= preview * 2)
    {
        printSeries(series);
        return;
    }

    // Print first 15 values
    for (size_t i = 0; i < preview; i++)
    {
        cout << series[i] << ", ";
    }

    cout << "..., ";

    // Print last 15 values
    for (size_t i = series.size() - preview;
         i < series.size();
         i++)
    {
        cout << series[i];

        if (i + 1 < series.size())
        {
            cout << ", ";
        }
    }

    cout << endl;
}


// ============================================================
// MEASURE ITERATIVE LATENCY
// ============================================================

double measureIterative(int n, vector<string>& result)
{
    auto T1 = high_resolution_clock::now();

    result = calculateVarionacciIterative(n);

    auto T2 = high_resolution_clock::now();

    double latency =
        duration<double, milli>(T2 - T1).count();

    return latency;
}


// ============================================================
// MEASURE RECURSIVE LATENCY
// ============================================================

double measureRecursive(int n, vector<string>& result)
{
    auto T1 = high_resolution_clock::now();

    result = calculateVarionacciRecursive(n);

    auto T2 = high_resolution_clock::now();

    double latency =
        duration<double, milli>(T2 - T1).count();

    return latency;
}


// ============================================================
// MAIN FUNCTION
// ============================================================

int main()
{
    cout << "====================================================\n";
    cout << "           DATA STRUCTURES & ALGORITHMS\n";
    cout << "                 ASSIGNMENT # 1\n";
    cout << "                  VARIONACCI SERIES\n";
    cout << "====================================================\n\n";


    // --------------------------------------------------------
    // PART 1: CalculateVarionacci(5)
    // --------------------------------------------------------

    cout << "PART 1: CalculateVarionacci(5)\n";
    cout << "--------------------------------------------\n";

    vector<string> example =
        calculateVarionacciIterative(5);

    cout << "Output: ";

    printSeries(example);


    // --------------------------------------------------------
    // PART 2: ITERATIVE ALGORITHM
    // --------------------------------------------------------

    cout << "\nPART 2: Iterative Algorithm\n";
    cout << "--------------------------------------------\n";

    vector<string> iterative10 =
        calculateVarionacciIterative(10);

    cout << "First 10 numbers:\n";

    printSeries(iterative10);


    // --------------------------------------------------------
    // PART 3: RECURSIVE ALGORITHM
    // --------------------------------------------------------

    cout << "\nPART 3: Recursive Algorithm\n";
    cout << "--------------------------------------------\n";

    vector<string> recursive10 =
        calculateVarionacciRecursive(10);

    cout << "First 10 numbers:\n";

    printSeries(recursive10);


    // --------------------------------------------------------
    // PART 4: LATENCY TEST
    // --------------------------------------------------------

    cout << "\nPART 4: LATENCY RESULTS\n";
    cout << "====================================================\n";

    cout << fixed << setprecision(6);

    cout << left
         << setw(15) << "Values"
         << setw(25) << "Iterative (ms)"
         << setw(25) << "Recursive (ms)"
         << endl;

    cout << string(65, '-') << endl;


    int testValues[] =
    {
        10,
        20,
        50,
        100,
        300
    };


    for (int n : testValues)
    {
        vector<string> iterativeResult;
        vector<string> recursiveResult;

        double iterativeTime =
            measureIterative(n, iterativeResult);

        double recursiveTime =
            measureRecursive(n, recursiveResult);

        cout << left
             << setw(15) << n
             << setw(25) << iterativeTime
             << setw(25) << recursiveTime
             << endl;
    }


    // --------------------------------------------------------
    // PART 5: COMPLETE OUTPUT FOR 20 VALUES
    // --------------------------------------------------------

    cout << "\nPART 5: COMPLETE OUTPUT FOR 20 VALUES\n";
    cout << "--------------------------------------------\n";

    vector<string> twenty =
        calculateVarionacciIterative(20);

    printSeries(twenty);


    // --------------------------------------------------------
    // PART 6: OUTPUT FOR 50 VALUES
    // --------------------------------------------------------

    cout << "\nPART 6: OUTPUT FOR 50 VALUES\n";
    cout << "--------------------------------------------\n";

    vector<string> fifty =
        calculateVarionacciIterative(50);

    printPreview(fifty);


    // --------------------------------------------------------
    // PART 7: OUTPUT FOR 100 VALUES
    // --------------------------------------------------------

    cout << "\nPART 7: OUTPUT FOR 100 VALUES\n";
    cout << "--------------------------------------------\n";

    vector<string> hundred =
        calculateVarionacciIterative(100);

    printPreview(hundred);


    // --------------------------------------------------------
    // PART 8: OUTPUT FOR 300 VALUES
    // --------------------------------------------------------

    cout << "\nPART 8: OUTPUT FOR 300 VALUES\n";
    cout << "--------------------------------------------\n";

    vector<string> threeHundred =
        calculateVarionacciIterative(300);

    printPreview(threeHundred);


    // --------------------------------------------------------
    // PROGRAM FINISHED
    // --------------------------------------------------------

    cout << "\n====================================================\n";
    cout << "Program completed successfully.\n";
    cout << "====================================================\n";

    return 0;
}