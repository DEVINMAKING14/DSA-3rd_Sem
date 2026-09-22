#include<stdio.h>

void search(int data[], int length, int key){
    int located = 0;
    for(int offset=0; offset<length; offset++){
        if(key == *(data + offset)){
            printf("%d was found at arr[%d]", key, offset);
            located = 1;
            break;
        }
    }
    if(!located){
        printf("%d was not found!", key);
    }
}

int main(){
    int keyValue;
    int data[] = {10,15, 20, 25, 30, 35, 40, 45, 50, 55, 60, 65, 70};
    int length = sizeof(data)/ sizeof(*data);
    printf("Enter the number you are searching for : ");
    scanf("%d", &keyValue);
    search(data, length, keyValue);
}