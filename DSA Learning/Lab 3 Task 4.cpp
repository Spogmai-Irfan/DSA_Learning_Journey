#include <iostream>
#include <string>
using namespace std;

class Stack
{
private:
    char arr[100];
    int top;

public:

    Stack()
    {
        top = -1;
    }

    void push(char ch)
    {
        top++;
        arr[top] = ch;
    }

    char pop()
    {
        char ch = arr[top];
        top--;
        return ch;
    }

    bool isEmpty()
    {
        return top == -1;
    }
};

int main()
{
    Stack s;
    string expression;

    cout << "Enter an expression: ";
    cin >> expression;

    bool balanced = true;

    for (int i = 0; i < expression.length(); i++)
    {
        if (expression[i] == '(')
        {
            s.push('(');
        }
        else if (expression[i] == ')')
        {
            if (s.isEmpty())
            {
                balanced = false;
                break;
            }

            s.pop();
        }
    }

    if (!s.isEmpty())
    {
        balanced = false;
    }

    if (balanced)
    {
        cout << "Balanced" << endl;
    }
    else
    {
        cout << "Not Balanced" << endl;
    }

    return 0;
}