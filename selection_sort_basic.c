#include<stdio.h>

void selectionSort(int data[], int length){
    for(int pass=0; pass<length-1; pass++){
        for(int index=0; index<length; index++){
            printf("%d", data[index]);
            if(index<length-1){
                printf(", ");
            }
        }
        printf("\n");
    	int smallestIndex = pass;
        for(int index=pass+1; index<length; index++){
            if(data[smallestIndex]>data[index]){
                int swapValue = data[index];
                data[index] = data[smallestIndex];
                data[smallestIndex] = swapValue;
            }
        }
    }
}

int main(){
    int values[] = {7,2,6,8,9,1,5,4,3};
    int length = sizeof(values)/sizeof(values[0]);
    selectionSort(values, length);
    for(int pass=0; pass<length; pass++){
        printf("%d", values[pass]);
        if(pass<length-1){
            printf(", ");
        }
    }
}