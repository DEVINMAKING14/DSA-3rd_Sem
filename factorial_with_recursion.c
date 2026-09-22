#include<stdio.h>

int factorial(int number){
    if(number==0){
        return 1;
    }
    return number* factorial(number-1);
}

int main(){
    int number;
    printf("Enter your number : ");
    scanf("%d", &number);
    printf("Factorial of %d = %d",number,factorial(number));
}