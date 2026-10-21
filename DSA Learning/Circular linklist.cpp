
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

void insert(int value) {
    Node* newNode = new Node;
    newNode->data = value;

    if (head == NULL) {
        head = newNode;
        newNode->next = head;
    } else {
        Node* temp = head;

        while (temp->next != head) {
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->next = head;
    }
}

void display() {
    if (head == NULL) {
        cout << "List is empty\n";
        return;
    }

    Node* temp = head;

    cout << "Circular Linked List: ";

    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);

    cout << endl;
}

// Delete first node
void deleteFirst() {
    if (head == NULL) {
        cout << "List is empty\n";
        return;
    }

    if (head->next == head) {
        delete head;
        head = NULL;
        return;
    }

    Node* temp = head;
    Node* last = head;

    while (last->next != head) {
        last = last->next;
    }

    head = head->next;
    last->next = head;

    delete temp;
}

int main() {
    insert(10);
    insert(20);
    insert(30);

    display();

    deleteFirst();

    display();

    return 0;
}
