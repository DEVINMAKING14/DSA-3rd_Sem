#include<stdio.h>
#define MAX 5
int topIndex=-1;
int items[MAX];

int isFull(){
    return topIndex==MAX-1;
}

int isEmpty(){
    return topIndex==-1;
}

void push(int value){
    if(isFull()) printf("Stack Full\n");
    else{
        topIndex++;
        items[topIndex] = value;
    }
}

void pop(){
    if(isEmpty()) printf("Stack is empty\n");
    else topIndex--;
}

void peek(){
    if(isEmpty()){
        printf("Stack is empty!\n");
        return;
    }
    printf("Peeked top of the stack and found : %d\n", items[topIndex]);
}

void display(){
    if(isEmpty()){
        printf("Stack is empty\n");
        return;
    }
    printf("|----|\n");
    for(int index=topIndex; index>=0; index--) printf("| %d |\n", items[index]);
    printf("|----|");
    printf("\n\n");
}

int main(){
    pop();
    push(10);
    push(20);
    push(30);
    display();
    push(40);
    peek();
    push(51);
    peek();
    push(60);
    display();
    peek();
    pop();
    display();
    pop();
    display();
    pop();
    display();
    pop();
    pop();
    display();
    return 0;
}