#include <iostream>
using namespace std;

class Queue
{
private:
    int arr[10];
    int front;
    int rear;

public:
    Queue()
    {
        front = 0;
        rear = -1;
    }

    void insert(int value)
    {
        if (rear == 9)
        {
            cout << "Queue is Full!" << endl;
            return;
        }

        rear++;
        arr[rear] = value;
    }

    int count()
    {
        if (rear == -1)
            return 0;

        return rear - front + 1;
    }
};

int main()
{
    Queue q;

    q.insert(10);
    q.insert(20);
    q.insert(30);
    q.insert(40);

    cout << "Total elements = "
         << q.count() << endl;

    return 0;
}