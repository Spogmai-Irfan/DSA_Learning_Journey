//Example 1
#include<iostream>
using namespace std;
int main(){
    int arr[6]={1,4,5,6,7,8};
    int sum =0;
    for(int i=0;i<6;i++){
        sum=arr[i]+sum;
    }
    cout<<sum<<endl;
    return 0;
    
}
//Example 2
#include<iostream>
using namespace std;
int main(){
    int arr[4]={2,3,4,5};
    int sum=0;
    for (int i=0;i<4;i++){
        sum +=arr[i];
    }
    double average =(double)sum/4;
    cout<<average<<endl;
    return 0;
}
//Example 3
#include<iostream>
using namespace std;
int main(){
    int arr[7]={1,2,4,5,6,7,9};
    int difference=arr[6]-arr[4];
    cout<<difference<<endl;
    return 0;
}