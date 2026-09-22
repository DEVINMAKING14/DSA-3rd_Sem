#include<stdio.h>

int delete(int data[], int position, int length){
    for(int index=position; index<length; index++){
        data[index] = data[index+1];
    }
}

int main(){
    int data[] = {10,20,30,40,45,50,60};
    int currentLength = 7;
    int deletePosition;
    printf("Enter the position of element you wanna delete : ");
    scanf("%d", &deletePosition);

    delete(data, deletePosition, currentLength);
    
    currentLength--;
    for(int index=0; index<currentLength; index++){
        printf("%d", data[index]);
        if(index>=0 && index< currentLength-1){
            printf(", ");
        }
    }
}