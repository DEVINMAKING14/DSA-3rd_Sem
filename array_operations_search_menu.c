#include<stdio.h>
#include<string.h>
#include<ctype.h>

void options(){
    printf("-----------------------------------------\n");
    printf("|  1. Display the entire array          |\n");
    printf("|  2. Insert an element in an array     |\n");
    printf("|  3. Delete an element from an array   |\n");
    printf("|  4. Linear searching from 1D array    |\n");
    printf("|  5. Binary searching using iteration  |\n");
    printf("|  6. Binary searching using recurtion  |\n");
    printf("-----------------------------------------\n");
}

int insert(int data[], int length, int key, int position){
    for(int index=length; index>=position; index--){
        data[index] = data[index-1];
    }
    data[position] = key;
}

int delete(int data[], int position, int length){
    for(int index=position; index<length; index++){
        data[index] = data[index+1];
    }
}

void search(int data[], int length, int key){
    int located = 0;
    for(int index=0; index<length; index++){
        if(key == data[index]){
            printf("%d was found at : array[%d]", key, index);
            located = 1; 
            break;
        }
    }
    if(!located){
        printf("%d was not found in the array", key);
    }
}

int binary_search1(int data[], int left, int right, int key){
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

int binary_search2(int data[], int left, int right, int key){
    if(left <= right){
        int midpoint = left + (right - left)/2;
        if(key == data[midpoint]){
            return midpoint;
        }
        if(key > data[midpoint]){
            return binary_search2(data, midpoint+1, right, key);
        }
        else{
            return binary_search2(data, left, midpoint - 1, key);
        }
    }
    return -1;
}

int main(){
    char again = 'y';
    int data[] = {10,15,20,25,30,35,40,45,50,55,60};
    do{
        options();

        int currentLength = sizeof(data)/ sizeof(data[0]);
        int key;
        int position;
        int searchResult;

        int option;
        printf("Enter your choice : ");
        scanf("%d", &option);

        switch(option){
            case 1:
                //Display
                for(int index=0; index<currentLength; index++){
                    printf("%d", data[index]);
                    if(index>=0 && index<currentLength-1){
                        printf(", ");
                    }
                }
                break;
            case 2:
                printf("Enter the value you wanna insert : ");
                scanf("%d", &key);
                printf("Enter the position where you wanna insert : ");
                scanf("%d", &position);

                insert(data, currentLength, key, position);
                currentLength++;

                //Display
                for(int index=0; index<currentLength; index++){
                    printf("%d", data[index]);
                    if(index>=0 && index<currentLength-1){
                        printf(", ");
                    }
                }
                break;
            case 3:
                printf("Enter the position of element you wanna delete : ");
                scanf("%d", &position);

                delete(data, position, currentLength);
                currentLength--;

                //Display
                for(int index=0; index<currentLength; index++){
                    printf("%d", data[index]);
                    if(index>=0 && index< currentLength-1){
                        printf(", ");
                    }
                }
                break;
            case 4:
                printf("Enter the element you wanna search for : ");
                scanf("%d", &key);

                search(data, currentLength, key);
                break;
            case 5:{
                    printf("Enter the element you wanna search for : ");
                    scanf("%d", &key);

                    int searchResult = binary_search1(data, 0, currentLength-1, key);
        
                    if(searchResult != -1){
                        printf("%d was found at : array[%d]", key, searchResult);
                    }
                    else{
                        printf("%d was not found in the array!", key);
                    }
                    break;
                }
            case 6:{
                    printf("Enter the element you wanna search for : ");
                    scanf("%d", &key);

                    int searchResult = binary_search2(data, 0, currentLength-1, key);
        
                    if(searchResult != -1){
                        printf("%d was found at : array[%d]", key, searchResult);
                    }
                    else{
                        printf("%d was not found in the array!", key);
                    }
                    break;
                }
            default:
                printf("Please enter a valid option!");
        }

        //Repeatation
        printf("\n\nDo you want to do it again? (Y/N) : ");
        scanf(" %c", &again);
        again = tolower(again);
    }while(again == 'y');
    printf("---------------------\n");
    printf("|     Thank You     |\n");
    printf("---------------------");
}