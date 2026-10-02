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

    bool isEmpty()
    {
        return front == -1;
    }

    bool isFull()
    {
        return rear == 4;
    }

    void insert(int value)
    {
        if (isFull())
        {
            cout << "Queue is FULL!" << endl;
            return;
        }

        if (isEmpty())
            front = 0;

        rear++;
        arr[rear] = value;

        cout << value << " inserted." << endl;
    }

    void remove()
    {
        if (isEmpty())
        {
            cout << "Queue is EMPTY!" << endl;
            return;
        }

        cout << arr[front] << " deleted." << endl;

        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front++;
        }
    }
};

int main()
{
    Queue q;

    q.insert(10);
    q.insert(20);
    q.insert(30);

    q.remove();
    q.remove();

    return 0;
}