#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
};
int main(){
    Node* head=nullptr;
    Node* newNode;
    Node* temp;
    newNode=new Node();
    newNode->data=10;
    newNode->next=nullptr;
    head=newNode;
    newNode=new Node();
    newNode->data=20;
    newNode->next=nullptr;
    temp=head;
    while(temp->next!=nullptr){
        temp=temp->next;
    }
    temp->next=newNode;
    temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<endl;
        temp=temp->next;
    }
    cout<<"Null"<<endl;
    return 0;

}
//program 2
#include <iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
};
int main(){
    Node* head=new Node{20,nullptr};
    Node* newNode=new Node{30,nullptr};
    newNode->next=head;
    head=newNode;
    Node* temp=head;
    while (temp!=nullptr){
        cout<<temp->data<<endl;
        temp=temp->next;
    }
    return 0;
}
