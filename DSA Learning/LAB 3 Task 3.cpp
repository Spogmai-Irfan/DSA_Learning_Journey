#include <iostream>
using namespace std;

class DQueue
{
private:
    int arr[10];
    int front;
    int rear;
    int count;

public:

    DQueue()
    {
        front = 0;
        rear = -1;
        count = 0;
    }

    bool isEmpty()
    {
        return count == 0;
    }

    bool isFull()
    {
        return count == 10;
    }

    void insertRear(int value)
    {
        if (isFull())
        {
            cout << "Deque is full!" << endl;
            return;
        }

        rear = (rear + 1) % 10;
        arr[rear] = value;
        count++;

        cout << value << " inserted at rear." << endl;
        cout << "Rear = " << rear
             << " Front = " << front << endl;
    }

    void insertFront(int value)
    {
        if (isFull())
        {
            cout << "Deque is full!" << endl;
            return;
        }

        if (isEmpty())
        {
            front = rear = 0;
        }
        else
        {
            front = (front - 1 + 10) % 10;
        }

        arr[front] = value;
        count++;

        cout << value << " inserted at front." << endl;
        cout << "Rear = " << rear
             << " Front = " << front << endl;
    }

    void removeRear()
    {
        if (isEmpty())
        {
            cout << "Deque is empty!" << endl;
            return;
        }

        cout << arr[rear] << " removed from rear." << endl;

        if (count == 1)
        {
            front = 0;
            rear = -1;
        }
        else
        {
            rear = (rear - 1 + 10) % 10;
        }

        count--;

        cout << "Rear = " << rear
             << " Front = " << front << endl;
    }

    void removeFront()
    {
        if (isEmpty())
        {
            cout << "Deque is empty!" << endl;
            return;
        }

        cout << arr[front] << " removed from front." << endl;

        if (count == 1)
        {
            front = 0;
            rear = -1;
        }
        else
        {
            front = (front + 1) % 10;
        }

        count--;

        cout << "Rear = " << rear
             << " Front = " << front << endl;
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Deque is empty!" << endl;
            return;
        }

        cout << "\nIndex\tValue" << endl;

        int index = front;

        for (int i = 0; i < count; i++)
        {
            cout << index << "\t" << arr[index] << endl;
            index = (index + 1) % 10;
        }

        cout << "Front = " << front << endl;
        cout << "Rear = " << rear << endl;
    }
};

int main()
{
    DQueue dq;

    int choice;
    int value;

    do
    {
        cout << "\nPlease enter a number representing an operation "
             << "in the following list (-1 to quit):\n";

        cout << "1. InsertRear()" << endl;
        cout << "2. InsertFront()" << endl;
        cout << "3. RemoveRear()" << endl;
        cout << "4. RemoveFront()" << endl;
        cout << "5. Display()" << endl;

        cout << "\nUser enters >> ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter a value that you want to insert at Rear side: ";
            cin >> value;
            dq.insertRear(value);
            break;

        case 2:
            cout << "Enter a value that you want to insert at Front side: ";
            cin >> value;
            dq.insertFront(value);
            break;

        case 3:
            dq.removeRear();
            break;

        case 4:
            dq.removeFront();
            break;

        case 5:
            dq.display();
            break;

        case -1:
            cout << "Program terminated." << endl;
            break;

        default:
            cout << "Invalid choice!" << endl;
        }

    } while (choice != -1);

    return 0;
}