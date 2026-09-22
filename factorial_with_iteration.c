#include<stdio.h>

int factorial(int value);

int main(){
    int number=0;
    printf("Enter your number : ");
    scanf("%d", &number);
    printf("%d! = %d", number, factorial(number));
}

int factorial(int value){
    int result = 1;
    if(value < 1){
        return result;
    }
    else{
        while(value>1){
            result *= value;
            value--;
        }
    }
    return result;
}