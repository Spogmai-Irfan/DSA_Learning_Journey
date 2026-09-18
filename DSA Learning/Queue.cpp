//Example 1
#include<iostream>
using namespace std;
int main(){
    int queue[5];
    int front = 0,rear=-1;
    queue[++rear]=10;
    queue[++rear]=20;
    queue[++rear]=30;
    cout<<"Queue:";
    for(int i=front;i<=rear;i++){
        cout<<queue[i]<<" ";
    }
    cout<<"\nDeleted:"<<queue[front];
    front++;
    cout<<"\nQueue after deleltion:";
    for(int i=front;i<=rear;i++){
        cout<<queue[i]<<" ";
    }
    return 0;

}
//Example 2
#include<iostream>
using namespace std;
int queue[5];
int front = 0, rear = -1;
void enqueue(int value) {
    rear++;
    queue[rear] = value;
}
void dequeue(){
    cout<<"Deleted:"<<queue[front]<<endl;
    front++;
}
void display(){
    cout<<"Queue:";
    for(int i=front;i<=rear;i++){
        cout<<queue[i]<<" ";
    }
    cout<<endl;
}
int main(){
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();
    dequeue();
    display();
    return 0;
}
//Example 3
#include<iostream>
using namespace std;
int queue[5];
int front =0,rear =-1;
void enqueue(int value){
    rear++;
    queue[rear]=value;
}
void dequeue(){
    if(front>rear){
        cout<<"Queue is emmpty"<<endl;

    }
    else{
cout<<"deleted:"<<queue[front]<<endl;
front++;
    }
}
void display(){
    if (front>rear){
        
        cout<<"Queue is empty"<<endl;
    }
    else{
        cout<<"Queue:";
        for(int i=front;i<=rear;i++){
            cout<<queue[i]<<" ";
        }
        cout<<endl;
    }
}
int main(){
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();
    dequeue();
    display();
    dequeue();
    display();
    return 0;
}
