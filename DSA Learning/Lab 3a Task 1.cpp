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
            cout << "Queue is Full!" << endl;
            return;
        }

        rear++;
        arr[rear] = value;

        cout << value << " inserted into queue." << endl;
    }

    void remove()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty!" << endl;
            return;
        }

        cout << arr[0] << " removed from queue." << endl;

        // Shift elements to left
        for (int i = 0; i < rear; i++)
        {
            arr[i] = arr[i + 1];
        }

        rear--;
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty!" << endl;
            return;
        }

        cout << "Queue: ";

        for (int i = 0; i <= rear; i++)
        {
            cout << arr[i] << " ";
        }

        cout << endl;
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

    return 0;
}