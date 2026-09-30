#include <iostream>
using namespace std;

class Queue
{
private:
    int arr[5];
    int front;
    int rear;

public:
    Queue()
    {
        front = -1;
        rear = -1;
    }

    void Enqueue(int value)
    {
        if (rear == 4)
        {
            cout << "Queue is Full" << endl;
        }
        else
        {
            if (front == -1)
                front = 0;

            rear++;
            arr[rear] = value;

            cout << value << " inserted" << endl;
        }
    }

    void Dequeue()
    {
        if (front == -1 || front > rear)
        {
            cout << "Queue is Empty" << endl;
        }
        else
        {
            cout << arr[front] << " removed" << endl;
            front++;
        }
    }

    void Display()
    {
        if (front == -1 || front > rear)
        {
            cout << "Queue is Empty" << endl;
        }
        else
        {
            cout << "Queue: ";

            for (int i = front; i <= rear; i++)
            {
                cout << arr[i] << " ";
            }

            cout << endl;
        }
    }

    void Peek()
    {
        if (front == -1 || front > rear)
        {
            cout << "Queue is Empty" << endl;
        }
        else
        {
            cout << "Front element" << arr[front] << endl;
        }
    }
};

int main()
{
    Queue q;

    q.Enqueue(10);
    q.Enqueue(20);
    q.Enqueue(30);

    q.Display();

    q.Peek();

    q.Dequeue();

    q.Display();

    q.Peek();

    return 0;
}