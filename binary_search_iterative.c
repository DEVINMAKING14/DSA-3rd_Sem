#include<stdio.h>

int binary_search(int data[], int left, int right, int key){
    while(left<=right){
        int midpoint = left + (right - left)/2;
        if(key == data[midpoint]){
            return midpoint;
        }
        if(key > data[midpoint]){
            left = midpoint+1;
        }
        else{
            right = midpoint-1;
        }
    }
    return -1;
}

int main(){
    int data[] = {10,15,20,25,30,35,40,45,50,55,60,65};
    int length = sizeof(data)/ sizeof(data[0]);
    int key;
    printf("Enter the element you wanna search for : ");
    scanf("%d", &key);

    int position = binary_search(data, 0, length-1, key);
    
    if(position != -1){
        printf("%d was found at : array[%d]", key, position);
    }
    else{
        printf("%d was not found in the array!", key);
    }
}