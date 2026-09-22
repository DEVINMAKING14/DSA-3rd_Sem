#include<stdio.h>
#include<ctype.h>

void options(){
    printf("-----------------------\n");
    printf("|    1. Row Major     |\n");
    printf("|    2. Column Major  |\n");
    printf("-----------------------\n");
}

void rowmajor(int matrix[3][4], int baseAddress, int elementSize, int rowIndex, int lowestRow, int columnCount, int columnIndex, int lowestColumn){
    int result = baseAddress+elementSize*((rowIndex-lowestRow)*columnCount + (columnIndex-lowestColumn));
    printf("Address of arr[%d][%d] = %d is : %d\n", rowIndex-lowestRow,columnIndex-lowestColumn,matrix[rowIndex-lowestRow][columnIndex-lowestColumn], result);
}

void columnmajor(int matrix[3][4], int baseAddress, int elementSize, int rowIndex, int lowestRow, int rowCount, int columnIndex, int lowestColumn){
    int result = baseAddress+elementSize*((rowIndex-lowestRow)*rowCount + (columnIndex-lowestColumn));
    printf("Address of arr[%d][%d] = %d is : %d\n", rowIndex-lowestRow,columnIndex-lowestColumn,matrix[rowIndex-lowestRow][columnIndex-lowestColumn], result);
}

int main(){
    int matrix[3][4] = {{1,2,3,4},{5,6,7,11},{92,93,94,99}};
    int option, baseAddress,elementSize,rowIndex,columnIndex,lowestColumn,lowestRow,rowCount,columnCount;
    char again = 'y';
    do{
        options();
        printf("Enter your choice :");
        scanf("%d", &option);
        switch(option){
            case 1:
                printf("Enter the base address : ");
                scanf("%d", &baseAddress);
                printf("Enter the size of the datatype : ");
                scanf("%d", &elementSize);
                printf("Enter the row number you are looking for : ");
                scanf("%d", &rowIndex);
                printf("Enter the column number you are looking for : ");
                scanf("%d", &columnIndex);
                printf("Enter the lowest row index : ");
                scanf("%d", &lowestRow);
                printf("Enter the lowest column index : ");
                scanf("%d", &lowestColumn);
                printf("Enter the total number of columns : ");
                scanf("%d", &columnCount);
                rowmajor(matrix, baseAddress, elementSize, rowIndex, lowestRow, columnCount, columnIndex, lowestColumn);
                break;
            case 2:
                printf("Enter the base address : ");
                scanf("%d", &baseAddress);
                printf("Enter the size of the datatype : ");
                scanf("%d", &elementSize);
                printf("Enter the row number you are looking for : ");
                scanf("%d", &rowIndex);
                printf("Enter the column number you are looking for : ");
                scanf("%d", &columnIndex);
                printf("Enter the lowest row index : ");
                scanf("%d", &lowestRow);
                printf("Enter the lowest column index : ");
                scanf("%d", &lowestColumn);
                printf("Enter the total number of rows : ");
                scanf("%d", &rowCount);
                columnmajor(matrix, baseAddress, elementSize, rowIndex, lowestRow, rowCount, columnIndex, lowestColumn);
                break;
            default : 
                printf("Please enter a valid choice!");
        }

        printf("Do you wanna continue? (Y/N) : ");
        scanf(" %c", &again);
        again = tolower(again);
    }while(again == 'y');
    printf("------------------\n");
    printf("|   Thank You    |\n");
    printf("------------------\n");
}