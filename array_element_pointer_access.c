#include<stdio.h>

void access(int data[], int index, int length){
    if(index < length && index>=0){
        for(int offset=0; offset<length; offset++){
            if(*(data + index) == *(data + offset)){
                printf("arr[%d] = %d", offset, *(data + offset));
                break;
            }
        }
    }
    else{
        printf("Please enter a valid index!");
    }
}

int main(){
    int data[]={10,20,30,40,50,60,70,80,90};
    int length = sizeof(data)/sizeof(*data);
    int position;
    printf("Enter the index number : ");
    scanf("%d", &position);
    access(data, position, length);
}