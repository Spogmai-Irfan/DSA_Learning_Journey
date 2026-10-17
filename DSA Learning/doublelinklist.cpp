//Insertion at start
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

Node* head = nullptr;

void insertAtStart(int value) {
    Node* newNode = new Node;

    newNode->data = value;
    newNode->prev = nullptr;
    newNode->next = head;

    if (head != nullptr) {
        head->prev = newNode;
    }

    head = newNode;
}

void display() {
    Node* temp = head;

    while (temp != nullptr) {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }

    cout << "NULL" << endl;
}

int main() {
    insertAtStart(30);
    insertAtStart(20);
    insertAtStart(10);

    cout << "Doubly linked list: ";
    display();

    return 0;
}
//insertion at end

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

Node* head = nullptr;

void insertAtEnd(int value) {
    Node* newNode = new Node;

    newNode->data = value;
    newNode->prev = nullptr;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node* temp = head;

    while (temp->next != nullptr) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
}

void display() {
    Node* temp = head;

    while (temp != nullptr) {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }

    cout << "NULL" << endl;
}

int main() {
    insertAtEnd(10);
    insertAtEnd(20);
    insertAtEnd(30);

    cout << "Doubly linked list: ";
    display();

    return 0;
}
//insertion at any position

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

Node* head = nullptr;

void insertAtPosition(int value, int position) {
    if (position < 1) {
        cout << "Invalid position!" << endl;
        return;
    }

    Node* newNode = new Node;
    newNode->data = value;
    newNode->prev = nullptr;
    newNode->next = nullptr;

    // Insert at the start
    if (position == 1) {
        newNode->next = head;

        if (head != nullptr) {
            head->prev = newNode;
        }

        head = newNode;
        return;
    }

    Node* temp = head;

    // Move to the node before the required position
    for (int i = 1; i < position - 1 && temp != nullptr; i++) {
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Invalid position!" << endl;
        delete newNode;
        return;
    }

    // Connect the new node
    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != nullptr) {
        temp->next->prev = newNode;
    }

    temp->next = newNode;
}

void display() {
    Node* temp = head;

    while (temp != nullptr) {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }

    cout << "NULL" << endl;
}

int main() {
    insertAtPosition(10, 1);
    insertAtPosition(20, 2);
    insertAtPosition(30, 3);

    cout << "Before insertion: ";
    display();

    insertAtPosition(25, 3);

    cout << "After insertion: ";
    display();

    return 0;
}
