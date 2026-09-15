/Task 1
#include <iostream>
using namespace std;

int main()
{
    int n;

    cout << "Enter size of array: ";
    cin >> n;

    int arr[n];

    cout << "Enter " << n << " elements:" << endl;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int sum = 0;

    cout << "\nArray elements are: ";

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
        sum += arr[i];
    }

    cout << "\nSum of array elements = " << sum << endl;

    return 0;
// }
//Task 2
#include <iostream>
using namespace std;

int main()
{
    int arr[8];

    cout << "Enter 8 elements:" << endl;

    for (int i = 0; i < 8; i++)
    {
        cin >> arr[i];
    }

    cout << "\nElements in reverse order:" << endl;

    for (int i = 7; i >= 0; i--)
    {
        cout << arr[i] << " ";
    }

    cout << endl;

    return 0;
}
//Task 3
#include <iostream>
using namespace std;

int main()
{
    int num = 25;
    int *ptr;

    ptr = &num;

    cout << "Value of num = " << num << endl;

    cout << "Address of num = " << &num << endl;

    cout << "Address stored in pointer = " << ptr << endl;

    *ptr = 30;

    cout << "New value of num = " << num << endl;
    cout << "Value through pointer = " << *ptr << endl;

    return 0;
}
Task 4
#include <iostream>
using namespace std;

int main()
{
    int num;
    int *ptr;

    cout << "Enter an integer: ";
    cin >> num;

    ptr = &num;

    cout << "You entered: " << *ptr << endl;

    return 0;
}
//Task 5
#include <iostream>
using namespace std;

int main()
{
    float arr[10];

    cout << "Enter 10 float values:" << endl;

    for (int i = 0; i < 10; i++)
    {
        cin >> arr[i];
    }

    float *ptr = arr;

    cout << "\nElements at odd positions:" << endl;

    for (int i = 0; i < 10; i += 2)
    {
        cout << *(ptr + i) << " ";
    }

    cout << endl;

    return 0;
}
//Task 6
#include <iostream>
using namespace std;

class Car
{
private:
    int xPosition;
    int yPosition;
    int speed;

public:
    Car()
    {
        xPosition = 0;
        yPosition = 0;
        speed = 0;
    }

    Car(int x, int y)
    {
        xPosition = x;
        yPosition = y;
        speed = 0;
    }

    void accelerate()
    {
        speed++;
    }

    void decelerate()
    {
        if (speed > 0)
            speed--;
    }

    void moveForward()
    {
        yPosition++;
    }

    void moveBackwards()
    {
        yPosition--;
    }

    void turnLeft()
    {
        xPosition--;
    }

    void turnRight()
    {
        xPosition++;
    }

    void currState()
    {
        cout << "X Position: " << xPosition << endl;
        cout << "Y Position: " << yPosition << endl;
        cout << "Speed: " << speed << endl;
    }
};

int main()
{
    Car car(5, 10);

    cout << "Initial Car State:" << endl;
    car.currState();

    car.accelerate();
    car.accelerate();

    car.moveForward();
    car.turnRight();

    cout << "\nAfter movement:" << endl;
    car.currState();

    car.decelerate();

    cout << "\nAfter deceleration:" << endl;
    car.currState();

    return 0;
}
//Task 7
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Car
{
private:
    int xPosition;
    int yPosition;
    int speed;

public:

    Car()
    {
        xPosition = 0;
        yPosition = 0;
        speed = 0;
    }

    Car(int x, int y)
    {
        xPosition = x;
        yPosition = y;
        speed = 0;
    }

    void accelerate()
    {
        speed++;
    }

    void decelerate()
    {
        if (speed > 0)
            speed--;
    }

    void moveForward()
    {
        yPosition++;
    }

    void moveBackwards()
    {
        yPosition--;
    }

    void turnLeft()
    {
        xPosition--;
    }

    void turnRight()
    {
        xPosition++;
    }

    int getX()
    {
        return xPosition;
    }

    int getY()
    {
        return yPosition;
    }

    void currState(int carNumber)
    {
        cout << "Car " << carNumber
             << " -> X: " << xPosition
             << ", Y: " << yPosition
             << ", Speed: " << speed << endl;
    }
};

int main()
{
    srand(time(0));

    Car cars[10];

    for (int i = 0; i < 10; i++)
    {
        int x = rand() % 20;
        int y = rand() % 20;

        cars[i] = Car(x, y);
    }

    for (int iteration = 1; iteration <= 100; iteration++)
    {
        int carNumber = rand() % 10;

        int direction = (rand() % 4) + 1;

        cout << "Iteration: " << iteration << endl;
        cout << "Selected Car: " << carNumber << endl;

        switch (direction)
        {
        case 1:
            cars[carNumber].moveForward();
            cout << "Direction: Forward" << endl;
            break;

        case 2:
            cars[carNumber].moveBackwards();
            cout << "Direction: Backward" << endl;
            break;

        case 3:
            cars[carNumber].turnLeft();
            cout << "Direction: Left" << endl;
            break;

        case 4:
            cars[carNumber].turnRight();
            cout << "Direction: Right" << endl;
            break;
        }

        bool collisionFound = false;

        for (int i = 0; i < 10; i++)
        {
            for (int j = i + 1; j < 10; j++)
            {
                if (cars[i].getX() == cars[j].getX() &&
                    cars[i].getY() == cars[j].getY())
                {
                    cout << "!!! COLLISION !!!" << endl;
                    cout << "Car " << i
                         << " collided with Car " << j
                         << " at ("
                         << cars[i].getX() << ", "
                         << cars[i].getY() << ")" << endl;

                    collisionFound = true;
                }
            }
        }

        if (!collisionFound)
        {
            cout << "No collision detected." << endl;
        }


        cout << "\nCurrent State of All Cars:" << endl;

        for (int i = 0; i < 10; i++)
        {
            cars[i].currState(i);
        }
    }

    return 0;
}
