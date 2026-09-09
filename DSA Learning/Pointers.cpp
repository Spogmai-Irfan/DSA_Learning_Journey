//Example 1
#include<iostream>
using namespace std;
int main(){
    int a[]={34,55,44,33,33};
    int *p =a;
    for (int i=0;i<5;i++){
        cout<<*(p+i)<<" ";
    }
    return 0;
}
//Example 2
#include<iostream>
using namespace std;
int main(){
    int a[]={12,34,56,34,23};
    int *p=a;
    int sum =0;
    for(int i=0;i<5;i++){
        sum=sum+*(p+i);
    }
    cout<<"sum="<<sum;
    return 0;
}

//Example 3
#include<iostream>
using namespace std;
int main(){
    int a[5]={1,2,3,4,5};
    int *p=a;
    int largest=*p;
    for (int i=0;i<5;i++){
        if(*(p+i)>largest){
            largest=*(p+i);
        }
    }
    cout<<"largest"<<largest;
    return 0;

    }
//Example 4
#include<iostream>
using namespace std;
int main(){
    int a[]={1,2,3,4,5};
    int *p=a;
    int smallest=*p;
    for (int i=0;i<5;i++){
        if(*(p+i)<smallest){
            smallest=*(p+i);
        }
        cout<<"smallest"<<smallest;
        return 0;
    }
}
//Example 5
#include<iostream>
using namespace std;
int main(){
    int a[]={1,2,4,5,6,8,9,20};
    int *p=a;
    int count=0;
    for(int i=0;i<8;i++){
        if(*(p+i)%2==0){
            count++;
        }
    }
        cout<<"even number ="<<count;
        return 0;
    
    
}

