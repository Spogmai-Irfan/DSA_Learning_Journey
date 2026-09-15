//Arithmetic pointer
//Example 1
#include<iostream>
using namespace std;
int main(){
    int arr[4] = {1, 2, 3, 4};
    int *p=arr;
    cout<<*p<<endl;
    cout<<*(p+1)<<endl;
    cout<<*(p+2)<<endl;
    cout<<*(p+3)<<endl;
    return 0;
}
//Example 2
#include<iostream>
using namespace std;
int main(){
    int arr[3]={3,4,5};
    int *p=arr;
    cout<<*p<<endl;
    p++;
    cout<<*p<<endl;
    p++;
    cout<<*p<<endl;
    return 0;
}
//Example 3
#include<iostream>
using namespace std;
int main(){
    int a[5]={4,5,6,7,8};
    int *p=a;
    int sum =0;
    for(int i=0;i<5;i++){
        sum +=*(p+i);
    }
    cout<<sum<<endl;
    return 0;
}