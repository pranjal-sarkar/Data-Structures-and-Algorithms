// doubly linked list: insertion, deletion by value, display
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

typedef struct s{
    int data;
    struct s *prev;
    struct s *next;
}node;

// function prototypes
int menu();
void pushOp(int);
int popOp(int);
void display();

// global variables
node *start = NULL;

int main(){
    int choice;
    int item, pop;

    while(1){
        choice = menu();
        switch(choice){
            case 1: 
                printf("\nEnter value to push: ");
                scanf("%d", &item);
                pushOp(item);
                break;
            case 2:
                printf("\nEnter value to delete: ");
                scanf("%d", &item);
                pop = popOp(item);
                if(pop != INT_MIN)
                    printf("\nValue %d found and deleted successfully!\n", pop);
                else
                    printf("\nValue not found\n");
                break;
            case 3:
                display();
                break;
            default:
                printf("\nAborting Program!!!\n");
                exit(0);
        }
    }
}

int menu(){
    int choice;

    printf("\nDouble Linked List:");
    printf("\n1. Push Values\n2. Delete by value\n3. Display List");
    printf("\nYour Choice: ");
    scanf("%d", &choice);

    return choice;
}

void pushOp(int item){
    node *newnode, *temp;

    newnode = (node *)malloc(sizeof(node));

    if(newnode == NULL){
        printf("\nMemory Not Allocated. Push Operation Unsuccessfull.\n");
        return ;
    }

    newnode->data = item;
    newnode->prev = newnode->next = NULL;

    if(start == NULL){
        start = newnode;
        return ;
    }

    temp = start;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->prev = temp;
}

int popOp(int item){
    node *temp, *prevnode;

    if(start == NULL){
        printf("\nLinked List Empty. Pop Operation Unsuccessfull.\n");
        return INT_MIN;
    }
    else if(start->data == item){
        free(start);
        start = NULL;
        return item;
    }

    temp = start;
    while(temp->next != NULL){
        if(temp->data == item){
            prevnode = temp->prev;
            prevnode->next = temp->next;
            free(temp);
            temp = prevnode->next;
            temp->prev = prevnode;
            return item;
        }

        temp = temp->next;
    }

    if(temp->data == item){
        prevnode = temp->prev;
        free(temp);
        prevnode->next = NULL;
        return item;
    }

    return INT_MIN;
}

void display(){
    node *temp;

    if(start == NULL){
        printf("\nLinked List Empty.\n");
        return ;
    }

    printf("\nThe Linked List is:\n");

    temp = start;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}