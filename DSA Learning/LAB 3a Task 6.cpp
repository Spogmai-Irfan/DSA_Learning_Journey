#include <iostream>
using namespace std;

class CircularQueue
{
private:
    int arr[5];
    int front;
    int rear;

public:
    CircularQueue()
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
        return (rear + 1) % 5 == front;
    }

    void insert(int value)
    {
        if (isFull())
        {
            cout << "Queue is Full" << endl;
            return;
        }

        if (isEmpty())
        {
            front = rear = 0;
        }
        else
        {
            rear = (rear + 1) % 5;
        }

        arr[rear] = value;

        cout << value << " inserted" << endl;
    }

    void remove()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty" << endl;
            return;
        }

        cout << arr[front] << " deleted" << endl;

        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front = (front + 1) % 5;
        }
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty" << endl;
            return;
        }

        cout << "Circular Queue: ";

        int i = front;

        while (true)
        {
            cout << arr[i] << " ";

            if (i == rear)
                break;

            i = (i + 1) % 5;
        }

        cout << endl;
    }
};

int main()
{
    CircularQueue q;

    q.insert(10);
    q.insert(20);
    q.insert(30);
    q.insert(40);
    q.insert(50);

    q.display();

    q.remove();
    q.remove();

    q.insert(60);
    q.insert(70);

    q.display();

    return 0;
}