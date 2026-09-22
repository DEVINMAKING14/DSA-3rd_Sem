#include<stdio.h>
#define MAX 5
int frontIndex = -1;
int rearIndex = -1;
int items[MAX];

int isFull(){
    return rearIndex == MAX - 1;
}

int isEmpty(){
    return frontIndex == -1;
}

void enqueue(int value){
    if(isFull()) printf("Queue Full\n");
    else{
        if(frontIndex == -1) frontIndex = 0;
        rearIndex++;
        items[rearIndex] = value;
    }
}

void dequeue(){
    if(isEmpty()) printf("Queue Empty\n");
    else{
        frontIndex++;
        if(frontIndex>rearIndex) frontIndex=rearIndex=-1;
    }
}

void display(){
    if(isEmpty()){
        printf("Queue Empty\n");
        return;
    }
    for(int index=frontIndex; index<=rearIndex; index++) printf("%d ", items[index]);
    printf("\n");
}

int main(){
    dequeue();
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();
    enqueue(40);
    enqueue(50);
    enqueue(60);
    display();
    dequeue();
    display();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    display();
    return 0;
}