#include <iostream>
using namespace std;
struct Node{
    int data;
    Node* prev;
    Node* next;
};
int main(){
    Node* first = new Node();
    Node* sec = new Node();
    Node* third = new Node();

    first->data=10;
    sec->data=20;
    third->data=30;
    first->next=sec;
    sec->next=third;
    third->next=NULL;
    sec->prev=first;
    first->prev=NULL;
    cout<<"Forward traversal: ";
    Node* current = first;
    while(current != NULL){
        cout<<current->data<<" ";
        current = current->next;
    }
    cout<<endl;
    cout<<"Backward traversal: ";
    current = third;
    while(current != NULL){
        cout<<current->data<<" ";
        current = current->prev;
    }
    cout<<endl;
    return 0;
}

