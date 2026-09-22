#include <iostream>
using namespace std;

class Queue
{
private:
    int arr[10];
    int rear;

public:
    Queue()
    {
        rear = -1;
    }

    bool isEmpty()
    {
        return rear == -1;
    }

    bool isFull()
    {
        return rear == 9;
    }

    void insert(int value)
    {
        if (isFull())
        {
            cout << "Queue Overflow!" << endl;
        }
        else
        {
            rear++;
            arr[rear] = value;

            cout << value << " inserted into queue." << endl;
            cout << "Front = 0, Rear = " << rear << endl;
        }
    }

    void remove()
    {
        if (isEmpty())
        {
            cout << "Queue Underflow!" << endl;
        }
        else
        {
            cout << arr[0] << " deleted from queue." << endl;

            for (int i = 0; i < rear; i++)
            {
                arr[i] = arr[i + 1];
            }

            rear--;

            if (rear == -1)
            {
                cout << "Queue is now empty." << endl;
            }
            else
            {
                cout << "Front = 0, Rear = " << rear << endl;
            }
        }
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is empty." << endl;
        }
        else
        {
            cout << "\nFront = 0" << endl;
            cout << "Rear = " << rear << endl;

            cout << "Queue elements: ";

            for (int i = 0; i <= rear; i++)
            {
                cout << arr[i] << " ";
            }

            cout << endl;
        }
    }
};

int main()
{
    Queue q;

    q.insert(10);
    q.insert(20);
    q.insert(30);

    q.display();

    q.remove();

    q.display();

    q.insert(40);

    q.display();

    return 0;
}