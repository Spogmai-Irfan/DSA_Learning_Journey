//Task1
#include<iostream>
using namespace std;
int findMax(int arr[],int size)
{
   int max=arr[0];
   for (int i=1;i<size;i++)
   {
   if (arr[i]>max)
   max=arr[i];
}
return max;
}
int findMin(int arr[],int size){
   int min=arr[0];
   for (int i=1;i<size;i++)
   {
       if(arr[i]<min);{
       min=arr[i];
   }
}
return min;
}
int findsum(int arr[],int size)
{
   int sum=0;
   for (int i =0;i<size;i++){
       sum=sum+arr[i];
   }
   return sum;
   }
   double findAverage(int arr[],int size)
   {
       int sum=findsum(arr,size);
       return(double)sum/size;
   }
   int main()
   {
       int arr[]={10,20,40,39,28};
       int size = 5;
       cout<<"Maximum"<<findMax(arr,size)<<endl;
       cout<<"Minimum"<<findMin(arr,size)<<endl;
       cout<<"Sum"<<findsum(arr,size)<<endl;
       cout<<"Average"<<findAverage(arr,size)<<endl;
       return 0;
   }
//Task 2
#include <iostream>
using namespace std;

int main()
{
    int arr[100];
    int size;

    cout << "Enter the size of array: ";
    cin >> size;

    cout << "Enter " << size << " elements:\n";

    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    cout << "\nArray in reverse order: ";

    for (int i = size - 1; i >= 0; i--)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
//Task 3
#include <iostream>
using namespace std;

// Function to find minimum element
int findMin(int arr[], int size)
{
    int minimum = arr[0];

    for (int i = 1; i < size; i++)
    {
        if (arr[i] < minimum)
        {
            minimum = arr[i];
        }
    }

    return minimum;
}

int main()
{
    int arr[] = {25, 10, 35, 5, 20};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Array elements: ";

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    cout << "\nSmallest element = " << findMin(arr, size);

    return 0;
}
//Task 4
#include <iostream>
#include <string>
using namespace std;

class Employee
{
private:
    string name;
    string address;

public:
    // Constructor
    Employee(string n, string a)
    {
        name = n;
        address = a;
    }

    // Display function
    void display()
    {
        cout << "Name: " << name << endl;
        cout << "Address: " << address << endl;
    }
};

int main()
{
    // Create three Employee objects
    Employee employee1("Ali", "Lahore");
    Employee employee2("Ahmed", "Karachi");
    Employee employee3("Sara", "Islamabad");

    cout << "Employee Details\n";
    employee1.display();
    employee2.display();
    employee3.display();

    return 0;
}
//Task 5
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// Base class
class Employee
{
protected:
    string name;
    string address;

public:
    Employee(string n, string a)
    {
        name = n;
        address = a;
    }

    virtual double Calculate_salary() = 0;

    virtual void display()
    {
        cout << "Name: " << name << endl;
        cout << "Address: " << address << endl;
    }

    virtual ~Employee()
    {
    }
};


class Salaried_Emp : public Employee
{
private:
    double monthlySalary;

public:
    Salaried_Emp(string n, string a, double salary)
        : Employee(n, a)
    {
        monthlySalary = salary;
    }

    double Calculate_salary() override
    {
        return monthlySalary;
    }

    void display() override
    {
        Employee::display();

        cout << "Employee Type: Salaried Employee" << endl;
        cout << "Monthly Salary: $" << monthlySalary << endl;
        cout << "Calculated Salary: $" << Calculate_salary() << endl;
    }
};

class Hourly_Emp : public Employee
{
private:
    double hourlyRate;
    double hoursWorked;

public:
    Hourly_Emp(string n, string a, double rate, double hours)
        : Employee(n, a)
    {
        hourlyRate = rate;
        hoursWorked = hours;
    }

    double Calculate_salary() override
    {
        return hourlyRate * hoursWorked;
    }

    void display() override
    {
        Employee::display();

        cout << "Employee Type: Hourly Employee" << endl;
        cout << "Hourly Rate: $" << hourlyRate << endl;
        cout << "Hours Worked: " << hoursWorked << endl;
        cout << "Calculated Salary: $" << Calculate_salary() << endl;
    }
};

int main()
{

    Salaried_Emp employee1(
        "Ali",
        "Lahore",
        5000
    );

    Salaried_Emp employee2(
        "Ahmed",
        "Karachi",
        6000
    );

    
    Hourly_Emp employee3(
        "Sara",
        "Islamabad",
        25,
        160
    );

    cout << fixed << setprecision(2);

    cout << "EMPLOYEE 1 " << endl;
    employee1.display();

    cout << "\nEMPLOYEE 2" << endl;
    employee2.display();

    cout << "\nEMPLOYEE 3" << endl;
    employee3.display();

    return 0;
}

