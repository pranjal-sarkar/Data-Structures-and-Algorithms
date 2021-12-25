#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

#define max 1000

// function prototypes
int menu();
void queuePush(int[], int*, int);
int queuePop(int[], int*, int*);
void queueDisplay(int[], int, int);
int queuePeekValue(int[], int, int);

int main(){
    int queue[max];
    int front=-1, rear=-1;
    int choice;
    int item, poppedElement, peek;

    while(1){
        choice = menu();
        switch(choice){
            case 1:
                printf("\nEnter item to push into queue: ");
                scanf("%d", &item);
                queuePush(queue, &rear, item);
                break;
            case 2:
                poppedElement = queuePop(queue, &front, &rear);
                if (poppedElement != INT_MIN)
                    printf("\nPopped element is: %d\n", poppedElement);
                break;
            case 3:
                queueDisplay(queue, front, rear);
                break;
            case 4:
                peek = queuePeekValue(queue, front, rear);
                if (peek != INT_MIN)
                    printf("\nPeek Value is: %d\n", peek);
                break;
            default: 
                printf("\nWrong Input. Aborting Program!!!");
                exit(0);
        }
    }
}

int menu(){
    int choice;

    printf("\nQueue Implementation:");
    printf("\n1. Push Operation\n2. Pop Operation\n3. Display Operation\n4. Peek Value\n5. Exit");
    printf("\nYour choice: ");
    scanf("%d", &choice);

    return choice;
}

void queuePush(int queue[], int *rear, int item){
    if (*rear == max){
        printf("\nQueue Full. Push Operation Unsuccessful.\n");
        return ;
    }

    queue[++(*rear)] = item;
}

int queuePop(int queue[], int *front, int *rear){
    int poppedElement;

    if(*front < *rear){
        poppedElement = queue[++(*front)];
        return poppedElement;
    }
    else if(*rear == -1 || *front == *rear){
        printf("\nQueue Empty. Pop Operation Unsuccessful.\n");
        return INT_MIN;
    }
}

void queueDisplay(int queue[], int front, int rear){
    int i;

    if(rear == -1 || front == rear){
        printf("\nQueue Empty.\n");
        return ;
    }

    printf("\nQueue Elements:\n");
    for(i=front + 1;i<=rear;i++){
        printf("%d ", queue[i]);
    }

    printf("\n");
}

int queuePeekValue(int queue[], int front, int rear){
    int peek;

    if(front == rear || rear == -1){
        printf("\nQueue Empty.\n");
        return INT_MIN;
    }

    peek = queue[front + 1];
    return peek;
}