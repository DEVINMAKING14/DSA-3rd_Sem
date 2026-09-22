#include<stdio.h>

void display(int data[], int length){
	for(int pass=0; pass<length; pass++){
        printf("%d", data[pass]);
        if(pass<length-1){
            printf(", ");
        }
    }
}
void swap(int *first, int *second){
	int swapValue = *first;
	*first = *second;
	*second = swapValue;
}

void selectionSort(int data[], int length){
    for(int pass=0; pass<length/2; pass++){
    	int smallestIndex = pass;
    	int largestIndex = pass;
    	int startIndex = pass;
		int endIndex = length-pass-1;
        for(int index=startIndex; index<=endIndex; index++){
            if(data[smallestIndex]>data[index]){
                smallestIndex = index;
            }
            if(data[largestIndex]<data[index]){
                largestIndex = index;
            }
        }
        swap(&data[smallestIndex], &data[startIndex]);
        
        if(largestIndex == startIndex){
            largestIndex = smallestIndex;
        }
        
        swap(&data[largestIndex], &data[endIndex]);

        display(data, length);
        printf("\n");
    }
}

int main(){
    int values[] = {7,2,6,8,9,1,5,4,3};
    int length = sizeof(values)/sizeof(values[0]);
    selectionSort(values, length);
    display(values, length);
}