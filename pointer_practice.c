#include<stdio.h>

int main(){
    // * -> Value at
    // & -> Address of
    int value = 25;
    int *pointer = &value;
    int **pointerToPointer = &pointer;
    printf("%d, %d\n", *pointer, **pointerToPointer);
    (*pointer)--;
    printf("%d, %d\n", *pointer, value);
    value+=10;
    printf("%d\n", *pointer);
    int otherValue = 44;
    *pointerToPointer = &otherValue;
    (**pointerToPointer)-=4;
    printf("%d, %d, %d", **pointerToPointer, *pointer, value);
}