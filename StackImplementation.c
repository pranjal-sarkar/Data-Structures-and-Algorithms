// Stack Implementation
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

#define max 1000

// function prototypes
int menu();
void stackPush(int[], int*, int);
int stackPop(int[], int*);
void stackDisplay(int[], int);
int stackPeekValue(int[], int);

int main(){
    int arr[max];
    int top=-1;
    int choice, item, poppedElement, peek;

    while(1){
        choice = menu();
        switch(choice){
            case 1: 
                printf("Enter Data to push into stack: ");
                scanf("%d", &item);
                stackPush(arr, &top, item);
                break;
            case 2:
                poppedElement = stackPop(arr, &top);
                if (poppedElement != INT_MIN)
                    printf("\nPopped Data from stack is: %d\n", poppedElement);
                break;
            case 3:
                stackDisplay(arr, top);
                break;
            case 4:
                peek = stackPeekValue(arr, top);
                if (peek != INT_MIN)
                    printf("\nPeek Value of stack is: %d\n", peek);
                break;
            default:
                printf("\nWrong Option Chosen. Aborting Program!!\n");
                exit(0);
        }
    }
}

int menu(){
    int choice;

    printf("\nStack Implementation:");
    printf("\n1. Push Operation\n2. Pop Operation\n3. Display Operation\n4. Peek Value\n5. Exit");
    printf("\nYour Choice: ");
    scanf("%d", &choice);

    return choice;
}

void stackPush(int arr[], int *top, int item){
    (*top)++;

    if (*top == max){
        printf("\nStack Full. Push Operation Unsuccessful");
        return ;
    }

    arr[*top] = item;
}

int stackPop(int arr[], int *top){
    int poppedElement;

    if (*top == -1){
        printf("\nStack Empty. Pop Operation Unsuccessful\n");
        return INT_MIN;
    }

    poppedElement = arr[*top];
    *top = *top - 1;

    return poppedElement;
}

void stackDisplay(int arr[], int top){
    int i;

    if(top == -1){
        printf("\nStack Empty\n");
        return ;
    }
    printf("\nStack Elements are: \n");
    for(i=0;i<=top;i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int stackPeekValue(int arr[], int top){
    int peekVal;

    if(top == -1){
        printf("\nStack Empty.\n");
        return INT_MIN;
    }

    peekVal = arr[top];
    return peekVal;
}