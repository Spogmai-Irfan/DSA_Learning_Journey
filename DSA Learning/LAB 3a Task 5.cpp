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
        front = -1;
        rear = -1;
    }

    void insert(int value)
    {
        if (rear == 9)
        {
            cout << "Queue is Full" << endl;
            return;
        }

        if (front == -1)
            front = 0;

        rear++;
        arr[rear] = value;
    }

    void displayFrontRear()
    {
        if (front == -1)
        {
            cout << "Queue is Empty" << endl;
            return;
        }

        cout << "Front element = " << arr[front] << endl;
        cout << "Rear element = " << arr[rear] << endl;
    }
};

int main()
{
    Queue q;

    q.insert(10);
    q.insert(20);
    q.insert(30);
    q.insert(40);

    q.displayFrontRear();

    return 0;
}