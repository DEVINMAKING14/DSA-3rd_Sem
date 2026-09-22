//Take 2 arrays, implement such a sorting where on array so that after each iteration smallest element goes to left, and on array 2 so that after each iteration the element goes to its correct position. Once the sorting is done on both the array combine them in sorted order to make a big array.

#include<stdio.h>

void swap(int *first, int *second){
	int swapValue = *first; 
	*first = *second;
	*second = swapValue;
}

void insertionSort(int nums[], int numsSize){
	for(int index=1; index<numsSize; index++){
		int value = nums[index];
		int innerIndex = index-1;
		while(innerIndex>=0 &&  value<nums[innerIndex]){
			nums[innerIndex+1] = nums[innerIndex];
			innerIndex--;
		}
		nums[innerIndex+1] = value;
	}
}

void selectionSort(int nums[], int numsSize){
	for(int index=0; index<numsSize-1; index++){
		int smallestIndex = index;
		for(int innerIndex=index+1; innerIndex<numsSize; innerIndex++){
			if(nums[innerIndex]<nums[smallestIndex]){
				smallestIndex = innerIndex;
			}
		}
		swap(&nums[index], &nums[smallestIndex]);
	}
}

void merge(int firstArray[], int secondArray[], int mergedArray[],int firstLength, int secondLength, int mergedLength){
	
	int index=0 ,innerIndex=0 ,mergeIndex=0;
	while(index<firstLength && innerIndex<secondLength){
		if(firstArray[index] <= secondArray[innerIndex]){
			mergedArray[mergeIndex] = firstArray[index];
			index++;
		}
		else{
			mergedArray[mergeIndex] = secondArray[innerIndex];
			innerIndex++;
		}
		mergeIndex++;
	}
	while(index<firstLength){
		mergedArray[mergeIndex] = firstArray[index];
		index++;
		mergeIndex++;
	}
	while(innerIndex<secondLength){
		mergedArray[mergeIndex] = secondArray[innerIndex];
		innerIndex++;
		mergeIndex++;
	}
}

int main(){
	int firstArray[] = {7,2,9,4,1,8,5,3,6};
	int secondArray[] = {14, 18, 11, 16, 13, 10, 17, 12, 15};
	int firstLength = sizeof(firstArray)/sizeof(*firstArray);
	int secondLength = sizeof(secondArray)/sizeof(*secondArray);
	int mergedLength = firstLength + secondLength;
	int mergedArray[mergedLength];
	
	selectionSort(firstArray, firstLength);
	insertionSort(secondArray, secondLength);
	merge(firstArray, secondArray, mergedArray, firstLength, secondLength, mergedLength);
	
	for(int index=0; index<firstLength; index++){
		printf("%d", firstArray[index]);
		if(index<firstLength-1) printf(", ");
	}
	printf("\n");
	
	for(int index=0; index<secondLength; index++){
		printf("%d", secondArray[index]);
		if(index<secondLength-1) printf(", ");
	}
	printf("\n");
	
	for(int index=0; index<mergedLength; index++){
		printf("%d", mergedArray[index]);
		if(index<mergedLength-1) printf(", ");
	}
}
