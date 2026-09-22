#include <iostream>
using namespace std;

class Stack
{
private:
    int arr[10];
    int top;

public:
    Stack()
    {
        top = -1;
    }

    void push(int value)
    {
        if (top == 9)
        {
            cout << "Stack Overflow!" << endl;
        }
        else
        {
            top++;
            arr[top] = value;
            cout << value << " pushed into stack." << endl;
        }
    }

    void pop()
    {
        if (top == -1)
        {
            cout << "Stack Underflow!" << endl;
        }
        else
        {
            cout << arr[top] << " popped from stack." << endl;
            top--;
        }
    }

    void display()
    {
        cout << "\nTop pointer = " << top << endl;

        if (top == -1)
        {
            cout << "Stack is empty." << endl;
        }
        else
        {
            cout << "Stack elements in LIFO order:" << endl;

            for (int i = top; i >= 0; i--)
            {
                cout << arr[i] << " ";
            }

            cout << endl;
        }
    }
};

int main()
{
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    s.display();

    s.pop();

    s.display();

    return 0;
}