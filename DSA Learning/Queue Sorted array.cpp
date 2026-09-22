//Example 1
#include<iostream>
using namespace std;
class sortedQueue{
    int arr[10];
    int size;
    public :
    sortedQueue(){
        size=0;
    }
void enqueue(int value){
    int i= size-1;
    while(i>=0 && arr[i] >value){
        arr[i+1]=arr[i];
        i--;
    }
    arr[i+1]=value;
    size++;
}
void display(){
    cout<<"Queue: ";
    for (int i =0;i< size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
};
int main(){
    sortedQueue q;
    q.enqueue(5);
    q.enqueue(2);
    q.enqueue(8);
    q.enqueue(1);
    q.display();
    return 0;
}

//Example 2
#include<iostream>
using namespace std;
int main(){
    int queue[5]={5,2,8,1,9};
    cout<<"Sorted Queue:";
    for(int i=0;i<5;i++){
        cout<<queue[i]<<" ";
    }
    return 0;
}

//Example 3
#include<iostream>
using namespace std;
int queue[5]={3,4,5,6,7};
int n=5;
cout<<"queue: ";
for(int i=0;i<n;i++){
    cout<<queue[i]<<" ";

}
for (int i=0;i<n-1;i++){
    queue[i]=queue[i+1];
}
n--;
cout<<"after dequeue:";
for (int i=0;i<n;i++){
    cout<<queue[i]<<" ";
}
return 0;
}