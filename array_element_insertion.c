#include<stdio.h>

int insert(int data[], int length, int value, int position){
    for(int index=length; index>=position; index--){
        data[index] = data[index-1];
    }
    data[position] = value;
}

int main(){
    int data[10] = {10,30,40,50,60,80};
    int currentLength = 6;
    int value;
    int insertPosition;
    printf("Enter the number you wanna insert : ");
    scanf("%d", &value);
    printf("Enter the position where you wanna insert : ");
    scanf("%d", &insertPosition);

    insert(data, currentLength, value, insertPosition);

    currentLength++;
    for(int index=0; index<currentLength; index++){
        printf("%d", data[index]);
        if(index>=0 && index<currentLength-1){
            printf(", ");
        }
    }
}