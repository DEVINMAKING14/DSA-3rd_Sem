#include<stdio.h>

void search(int data[], int length, int key){
    int located = 0;
    for(int index=0; index<length; index++){
        if(key == data[index]){
            printf("%d was found at : array[%d]", key, index);
            located = 1; 
            break;
        }
    }
    if(!located){
        printf("%d was not found in the array", key);
    }
}

int main(){
    int data[] = {15,25,35,45,55,65,75,85,95};
    int length = sizeof(data)/sizeof(data[0]);
    int key;
    printf("Enter the element you wanna search for : ");
    scanf("%d", &key);

    search(data, length, key);
}