//constant
#include <stdio.h>
int main(){
    const int Days=7;
    printf("days:%d",Days);
    return 0;
}
//Area of square
#include<stdio.h>
int main(){
    const int side=10;
    int area=side*side;
    printf("area of square:%d",area);
    return 0;
}
//Area of rectangle
#include<stdio.h>
int main(){
    const int len=10;
    const int weig=6;
    int area=len*weig;
    printf("area of rectangle:%d",area);
    return 0;
}
//both constant and variable
#include<stdio.h>
int main(){
    const int constant_value=10;
    int variable_value=20;
    printf("constant value:%d",constant_value);
    printf("variable value:%d",variable_value);
    return 0;
}