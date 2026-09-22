#include<stdio.h>

void bubbleSort(int data[], int length){
	int swapCount=0;
    for(int pass=0; pass<length-1; pass++){
        for(int index=0; index<length-pass-1; index++){
            if(data[index]>data[index+1]){
                int swapValue = data[index];
                data[index] = data[index+1];
                data[index+1] = swapValue;
                swapCount++;
            }
        }
        if(!swapCount){
        	break;
		}
        for(int index=0; index<length; index++){
            printf("%d", data[index]);
            if(index<length-1){
                printf(", ");
            }
        }
        printf("\n");
    }
}

int main(){
    //int array[] = {7,2,6,8,9,1,5,4,3};
    int values[] = {1,2,3,4,5,6,7,8,9};
    int length = sizeof(values)/sizeof(values[0]);
    bubbleSort(values, length);
    for(int pass=0; pass<length; pass++){
        printf("%d", values[pass]);
        if(pass<length-1){
            printf(", ");
        }
    }
}