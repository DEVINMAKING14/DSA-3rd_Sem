//Take an array of 9 elements, try searching 1 element if its present right in the middle, return the index and then sort the left side array in decending order using the sorting that will work as the worst case scenario. And sort the right side using that algorithm which will work the best in descending. If it is not found in the middle, insert that element in the middle and then sort it in asc which will work best for this case.

#include<stdio.h>
#include<stdlib.h>

void merge(int data[], int start, int middle, int finish) {
    int leftIndex, rightIndex, mergeIndex;
    int leftCount = middle - start + 1;
    int rightCount = finish - middle;

    int *leftPart = (int *)malloc(leftCount * sizeof(int));
    int *rightPart = (int *)malloc(rightCount * sizeof(int));

    for (leftIndex = 0; leftIndex < leftCount; leftIndex++)
        leftPart[leftIndex] = data[start + leftIndex];
    for (rightIndex = 0; rightIndex < rightCount; rightIndex++)
        rightPart[rightIndex] = data[middle + 1 + rightIndex];

    leftIndex = 0;
    rightIndex = 0;
    mergeIndex = start;

    while (leftIndex < leftCount && rightIndex < rightCount) {
        if (leftPart[leftIndex] >= rightPart[rightIndex]) {
            data[mergeIndex] = leftPart[leftIndex];
            leftIndex++;
        } else {
            data[mergeIndex] = rightPart[rightIndex];
            rightIndex++;
        }
        mergeIndex++;
    }

    while (leftIndex < leftCount) {
        data[mergeIndex] = leftPart[leftIndex];
        leftIndex++;
        mergeIndex++;
    }

    while (rightIndex < rightCount) {
        data[mergeIndex] = rightPart[rightIndex];
        rightIndex++;
        mergeIndex++;
    }

    free(leftPart);
    free(rightPart);
}

void mergeSort(int data[], int start, int finish) {
    if (start < finish) {
        int middle = start + (finish - start) / 2;

        mergeSort(data, start, middle);
        mergeSort(data, middle + 1, finish);

        merge(data, start, middle, finish);
    }
}

void bubbleSort(int data[], int length){
    for(int leftIndex=0; leftIndex<length-1; leftIndex++){
        for(int rightIndex=0; rightIndex<length-leftIndex-1; rightIndex++){
            if(data[rightIndex] < data[rightIndex+1]){
                int swapValue = data[rightIndex];
                data[rightIndex] = data[rightIndex+1];
                data[rightIndex+1] = swapValue;
            }
        }
    }
}

void insertionSort(int data[], int length){
    for(int leftIndex=1; leftIndex<length; leftIndex++){
        int key = data[leftIndex];
        int rightIndex = leftIndex-1;
        while(rightIndex>=0 && key<data[rightIndex]){
            data[rightIndex+1] = data[rightIndex];
            rightIndex--;
        }
        data[rightIndex+1] = key;
    }
}

int binarySearch(int data[], int lower, int upper, int key){
    int middle = lower + (upper-lower)/2;
    if(key == data[middle]){
        bubbleSort(data, middle);
        mergeSort(data, middle+1, upper);
        return middle;
    }
    else{
        data[middle] = key;
        insertionSort(data, upper+1);
        return middle;
    }
}

int main(){
    int data[] = {2,4,6,8,10,12,14,16,18};
    int length = sizeof(data)/sizeof(*data);
    int key = 21;
    int middle = binarySearch(data, 0, length-1, key);

    printf("Middle Index : %d", middle);
    printf("\n");
    for(int leftIndex=0; leftIndex<length; leftIndex++){
        printf("%d ", data[leftIndex]);
    }
}
