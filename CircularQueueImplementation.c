#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

#define max 1000

// function prototypes
int menu();
void queuePush(int[], int*, int, int*);
int queuePop(int[], int*, int*, int*);
void queueDisplay(int[], int, int, int);
int queuePeekValue(int[], int, int, int);

int main(){
    int queue[max];
    int front=-1, rear=-1;
    int choice;
    int counter=0;
    int item, poppedElement, peek;

    while(1){
        choice = menu();
        switch(choice){
            case 1:
                printf("\nEnter item to push into queue: ");
                scanf("%d", &item);
                queuePush(queue, &rear, item, &counter);
                break;
            case 2:
                poppedElement = queuePop(queue, &front, &rear, &counter);
                if (poppedElement != INT_MIN)
                    printf("\nPopped element is: %d\n", poppedElement);
                break;
            case 3:
                queueDisplay(queue, front, rear, counter);
                break;
            case 4:
                peek = queuePeekValue(queue, front, rear, counter);
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

void queuePush(int queue[], int *rear, int item, int *counter){
    if (*counter == max){
        printf("\nQueue Full. Push Operation Unsuccessful.\n");
        return ;
    }

    *rear = (*rear + 1) % max;
    queue[*rear] = item;
    (*counter)++;
}

int queuePop(int queue[], int *front, int *rear, int *counter){
    int poppedElement;

    if(*counter != max){
        *front = (*front + 1) % max;
        poppedElement = queue[*front];
        (*counter)--;
        return poppedElement;
    }
    else{
        printf("\nQueue Empty. Pop Operation Unsuccessful.\n");
        return INT_MIN;
    }
}

void queueDisplay(int queue[], int front, int rear, int counter){
    int i;

    if(counter == 0){
        printf("\nQueue Empty.\n");
        return ;
    }

    printf("\nQueue Elements:\n");
    for(i = front + 1 ; i <= rear ; i = (i+1) % max){
        printf("%d ", queue[i]);
    }

    printf("\n");
}

int queuePeekValue(int queue[], int front, int rear, int counter){
    int peek;

    if(counter == 0){
        printf("\nQueue Empty.\n");
        return INT_MIN;
    }

    peek = queue[front + 1];
    return peek;
}