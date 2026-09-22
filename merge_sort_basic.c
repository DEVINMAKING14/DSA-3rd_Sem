#include<stdio.h>

void merge(int data[], int lower, int middle,int upper){
	int leftLength = middle-lower+1;
	int rightLength = upper-middle;
	int leftPart[leftLength], rightPart[rightLength];
	 
	for(int leftIndex=0; leftIndex<leftLength; leftIndex++)
		leftPart[leftIndex] = data[lower+leftIndex];
	for(int rightIndex=0; rightIndex<rightLength; rightIndex++)
		rightPart[rightIndex] = data[middle+rightIndex+1];
	int leftIndex=0 ,rightIndex=0 ,mergeIndex=lower;
	while(leftIndex<leftLength && rightIndex<rightLength){
		if(leftPart[leftIndex] <= rightPart[rightIndex]){
			data[mergeIndex] = leftPart[leftIndex];
			leftIndex++;
		}
		else{
			data[mergeIndex] = rightPart[rightIndex];
			rightIndex++;
		}
		mergeIndex++;
	}
	while(leftIndex<leftLength){
		data[mergeIndex] = leftPart[leftIndex];
		leftIndex++;
		mergeIndex++;
	}
	while(rightIndex<rightLength){
		data[mergeIndex] = rightPart[rightIndex];
		rightIndex++;
		mergeIndex++;
	}
}

void mergeSort(int data[], int lower, int upper){
	if(lower<upper){
		int middle = lower + (upper-lower)/2;
		mergeSort(data, lower, middle);
		mergeSort(data, middle+1, upper);
		merge(data, lower, middle, upper);
	}
}

int main(){
	int data[] = {4,7,1,9,8,5,3,2};
	int length = sizeof(data)/sizeof(*data);
	mergeSort(data, 0, length-1);
	
	for(int leftIndex=0; leftIndex<length; leftIndex++){
		printf("%d", data[leftIndex]);
		if(leftIndex<length-1) printf(", ");
	}
}