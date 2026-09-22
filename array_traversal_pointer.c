#include<stdio.h>

void display(int data[], int length){
    for(int index=0; index<length; index++){
        printf("%d", *(data + index));
        if(index<length-1){
            printf(", ");
        }
    }
}

int main(){
    int data[] = {10,15, 20, 25, 30, 35, 40, 45, 50, 55, 60, 65, 70};
    int length = sizeof(data)/ sizeof(*data);
    display(data, length);
}