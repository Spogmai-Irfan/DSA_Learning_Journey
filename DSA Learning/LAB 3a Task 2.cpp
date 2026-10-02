#include <iostream>
using namespace std;

class DeQueue
{
private:
    int arr[10];
    int front;
    int rear;

public:
    DeQueue()
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
        return (front == 0 && rear == 9) ||
               (front == rear + 1);
    }

    void insertRear(int value)
    {
        if (isFull())
        {
            cout << "Deque is Full!" << endl;
            return;
        }

        if (isEmpty())
        {
            front = rear = 0;
        }
        else if (rear == 9)
        {
            rear = 0;
        }
        else
        {
            rear++;
        }

        arr[rear] = value;

        cout << value << " inserted at Rear." << endl;
    }

    void insertFront(int value)
    {
        if (isFull())
        {
            cout << "Deque is Full!" << endl;
            return;
        }

        if (isEmpty())
        {
            front = rear = 0;
        }
        else if (front == 0)
        {
            front = 9;
        }
        else
        {
            front--;
        }

        arr[front] = value;

        cout << value << " inserted at Front." << endl;
    }

    void removeRear()
    {
        if (isEmpty())
        {
            cout << "Deque is Empty!" << endl;
            return;
        }

        cout << arr[rear] << " removed from Rear" << endl;

        if (front == rear)
        {
            front = rear = -1;
        }
        else if (rear == 0)
        {
            rear = 9;
        }
        else
        {
            rear--;
        }
    }

    void removeFront()
    {
        if (isEmpty())
        {
            cout << "Deque is Empty!" << endl;
            return;
        }

        cout << arr[front] << " removed from Front." << endl;

        if (front == rear)
        {
            front = rear = -1;
        }
        else if (front == 9)
        {
            front = 0;
        }
        else
        {
            front++;
        }
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Deque is Empty" << endl;
            return;
        }

        cout << "Deque: ";

        int i = front;

        while (true)
        {
            cout << arr[i] << " ";

            if (i == rear)
                break;

            i = (i + 1) % 10;
        }

        cout << endl;
    }
};

int main()
{
    DeQueue q;

    q.insertRear(23);
    q.insertFront(20);
    q.insertRear(30);

    q.display();

    q.removeFront();

    q.display();

    q.removeRear();

    q.display();

    return 0;
}