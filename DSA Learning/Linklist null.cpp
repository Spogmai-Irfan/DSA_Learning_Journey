#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
};
int main(){
    Node* head=nullptr;
    if(head==nullptr){
        cout<<"linked list is empty"<<endl;
    }
return 0;
    
}
// Program 2
#include <iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
};
int main(){
    Node* head=new Node;
    head->data=10;
    head->next=nullptr;
    cout<<head->data<<endl;
    if(head->next==nullptr){
        cout<<"next node is empty"<<endl;
    }
    return 0;
}
//Program 3
#include <iostream>
using namespace std ;
struct Node{
    int data;
    Node* next;
};
int main(){
    Node* head=new Node;
    Node* second=new Node;
    head->data=10;
    head->next=second;
    second->data=20;
    second->next=nullptr;
    cout<<head->data<<endl;
    cout<<second->data<<endl;
    cout<<second->next;
    delete head;
    delete second;
    return 0;
}