//Take an array of 10 elements randomly unsorted, implement the sorting which checks two adjacent elements and swaps them if needed and perform this sorting for 1 external loops iteration, then take that intermediate array and pass it to a sorting function which performs worst when the array is sorted

#include<stdio.h>

void swap(int *first, int *second){
	int swapValue = *first; 
	*first = *second;
	*second = swapValue;
}

int partition(int data[], int lower, int upper){
	int splitValue = data[upper];
	int passIndex = (lower - 1);	
	for(int elementIndex=lower; elementIndex<upper; elementIndex++){
		if(data[elementIndex]<=splitValue){
			passIndex++;
			swap(&data[passIndex], &data[elementIndex]);
		}
	}
	swap(&data[passIndex+1], &data[upper]);
	return (passIndex+1);
}

void quickSort(int data[], int lower, int upper){
	if(lower<upper){
		int splitValue = partition(data, lower, upper);
		quickSort(data, lower, splitValue-1);
		quickSort(data, splitValue+1, upper);
	}
}

void bubbleSort(int data[], int length){
	int passCount=0;
	for(int passIndex=0; passIndex<length-1; passIndex++){
		for(int elementIndex=0; elementIndex<length-passIndex-1; elementIndex++){
			if(data[elementIndex+1]<data[elementIndex]){
				swap(&data[elementIndex+1], &data[elementIndex]);
			}
		}
		passCount++;
		if(passCount==1){
			quickSort(data, 0, length);
			return;
		}
	}
}

int main(){
	int data[] = {4,5,7,9,1,3,8,2,6};
	int length = sizeof(data)/sizeof(*data);
	bubbleSort(data, length);
	
	for(int passIndex=0; passIndex<length; passIndex++){
		printf("%d", data[passIndex]);
		if(passIndex<length-1) printf(", ");
	}
}
