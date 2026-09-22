#include<stdio.h>

void access1D(int oneD[], int key){
    int located=0;
    for(int rowIndex=0; rowIndex<6; rowIndex++){
        if(key == oneD[rowIndex]){
            printf("%d found at : array1D[%d]\n", key, rowIndex);
            located=1;
            break;
        }
    }
    if(!located){
        printf("%d was not found in the array1D\n", key);
    }
}

void access2D(int twoD[][3], int key){
    int located=0;
    for(int rowIndex=0; rowIndex<2; rowIndex++){
        for(int colIndex=0; colIndex<3; colIndex++){
            if(key == twoD[rowIndex][colIndex]){
                printf("%d found at : array2D[%d][%d]\n", key, rowIndex, colIndex);
                located=1;
                break;
            }
        }
    }
    if(!located){
        printf("%d was not found in the array2D\n", key);
    }
}

int main(){
    int oneD[6] = {10, 35, 20, 40, 50, 60};
    int twoD[2][3] = {{10,30,50},{20,40,60}};

    int key;
    printf("Enter your number : ");
    scanf("%d", &key);
    
    access1D(oneD, key);
    access2D(twoD, key);

    //Traversing 1D array
    printf("\nTraversing 1D array : \n");
    for(int rowIndex=0; rowIndex<6; rowIndex++){
        printf("%d", oneD[rowIndex]);
        if(rowIndex>=0 && rowIndex<5){
            printf(", ");
        }
    }

    //Traversing 2D array
    printf("\n\nTraversing 2D array : \n");
    for(int rowIndex=0; rowIndex<2; rowIndex++){
        for(int colIndex=0; colIndex<3; colIndex++){
            printf("%d", twoD[rowIndex][colIndex]);
            if(colIndex>=0 && colIndex<2){
                printf(", ");
            }
        }
        printf("\n");
    }
}