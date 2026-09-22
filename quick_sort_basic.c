#include<stdio.h>

void swap(int *first, int *second){
	int swapValue = *first;
	*first = *second;
	*second = swapValue;	
}

int partition(int data[], int lower, int upper){
	int splitValue = data[upper];
	int boundary = (lower - 1);	
	for(int index=lower; index<upper; index++){
		if(data[index]<=splitValue){
			boundary++;
			swap(&data[boundary], &data[index]);
		}
	}
	swap(&data[boundary+1], &data[upper]);
	return (boundary+1);
}

void quickSort(int data[], int lower, int upper){
	if(lower<upper){
		int splitValue = partition(data, lower, upper);
		quickSort(data, lower, splitValue-1);
		quickSort(data, splitValue+1, upper);
	}
}

int main(){
	int data[] = {4,5,7,9,1,3,8,2,6};
	int length = sizeof(data)/sizeof(*data);
	quickSort(data, 0, length-1);
	
	for(int boundary=0; boundary<length; boundary++){
		printf("%d", data[boundary]);
		if(boundary<length-1) printf(", ");
	}
}