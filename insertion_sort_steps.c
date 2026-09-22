#include<stdio.h>

void insertionSort(int data[], int length){
    for(int pass=1; pass<length; pass++){
    	int value = data[pass];
    	int index = pass-1;
    	while(index>=0 && value<data[index]){
    		data[index+1] = data[index];
        	index--;
		}
		data[index+1] = value;
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
    int values[] = {7,2,6,8,9,1,5,4,3};
    int length = sizeof(values)/sizeof(*values);
    insertionSort(values, length);
    for(int pass=0; pass<length; pass++){
        printf("%d", values[pass]);
        if(pass<length-1){
            printf(", ");
        }
    }
}