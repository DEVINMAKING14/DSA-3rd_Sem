#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main(){
    char structureName[15];
    printf("Available data structures : \n1. Array\n2. Linked List\n3. Tree\n4. Graph\n\n");
    printf("Enter the data structure : ");
    fgets(structureName, sizeof(structureName), stdin);

    for(int index=0; structureName[index] != '\0'; index++){
        structureName[index] = tolower(structureName[index]);
    }
    structureName[strcspn(structureName, "\n")] = '\0';

    if(strcmp(structureName, "array") == 0){
        printf("Non-Primitive and Linear");
    }
    else if(strcmp(structureName, "linked list") == 0){
        printf("Non-Primitive and Linear");
    }
    else if(strcmp(structureName, "tree") == 0){
        printf("Non-Primitive and Non-Linear");
    }
    else if(strcmp(structureName, "graph") == 0){
        printf("Non-Primitive and Non-Linear");
    }
    else{
        printf("Please make sure to enter a valid data structure");
    }
}