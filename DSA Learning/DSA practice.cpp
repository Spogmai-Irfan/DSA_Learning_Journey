//Array Arithmetic
//Example 1
#include<stdio.h>
int main (){
int a[5] = {1, 2, 3, 4, 5};
for(int i = 0; i < 5; i++){
    printf("%d",a[i]);
}
return 0;
}

//Example 2
#include<stdio.h>
int main (){
int a[5] = {1, 2, 3, 4, 5};
int sum = 0;
for(int i = 0; i < 5; i++){
    sum += a[i];
}
printf("Sum: %d", sum);
return 0;
}

//Example 3
#include<stdio.h>
int main(){
    int a[5]={1,3,4,5,6};
    int result[5];
    for(int i = 0; i < 5; i++){
        result[i] = a[i] - 1;
    }
    printf("Result=%d",result);
    return 0;
}

//Example 4
#include<stdio.h>
int main(){
    int a[4]={1,2,3,4};
    printf("%d\n",a[0]/a[1]);
    printf("%d\n",a[1]/a[2]);
    printf("%d\n",a[2]*a[3]);
    return 0;
}

Example 5
#include <stdio.h>
int main(){
    int a[5]={10,35,40,60,75};
    for (int i=0;i<5;i++){
        if (a[i%2==0]){
            printf("%d\n",a[i]);
        }
    }
    return 0;
}

Example 6
#include<stdio.h>
int main(){
    int a[5]={10,35,40,60,75};
    int largest = a[0];
    int smallest=a[0];
    for (int i=1;i<5;i++){
        if (a[i] > largest){
            largest = a[i];
        }
        if (a[i] < smallest){
            smallest = a[i];
        }
    }
    printf("Largest: %d\n", largest);
    printf("Smallest: %d\n", smallest);
    return 0;
}