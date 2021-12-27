// SingleLinkedList: Creation, deletion by value, display
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

typedef struct s{
    int data;
    struct s *next;
}NODE;

// function prototypes
int menu();
void pushOperation(int);
int popOperation(int);
void displayOperation();

// global variables
NODE *root = NULL;
// NODE *temp;

int main(){
    int choice;
    int pop, item;

    while(1){
        choice = menu();
        switch(choice){
            case 1:
                printf("\nEnter Value to Insert: ");
                scanf("%d", &item);
                pushOperation(item);
                break;
            case 2:
                printf("\nEnter data value to pop: ");
                scanf("%d", &item);
                pop = popOperation(item);
                if(pop != INT_MIN)
                    printf("\nThe popped item is: %d\n", pop);
                break;
            case 3:
                displayOperation();
                break;
            default:
                printf("\nAborting Program!!!\n");
                exit(0);
        }
    }
}

int menu(){
    int choice;

    printf("\nSingle Linked List Operations:");
    printf("\n1. Insertion of value\n2. Deletion by value\n3. Display\n4. Exit");
    printf("\nYour Choice: ");
    scanf("%d", &choice);

    return choice;
}

void pushOperation(int item){
    NODE *newnode, *temp;
    
    newnode = (NODE *)malloc(sizeof(NODE));
    if(newnode == NULL){
        printf("\nMemory Not Allocated\n");
        return ;
    }

    newnode->data = item;
    newnode->next = NULL;

    if(root == NULL){
        root = newnode;
        temp = newnode;
    }
    else{
        temp = root;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

int popOperation(int item){
    NODE *prevnode, *temp;

    if(root == NULL){
        printf("\nLinked List is Empty. Pop Operation Unsuccessfull\n");
        return INT_MIN;
    }
    
    prevnode = temp = root;

    if(root->data == item){
        root = root->next;
        free(temp);
        return item;
    }

    while(temp != NULL){
        if(temp->data == item){
            (prevnode->next) = (temp->next);
            temp->next = NULL;
            free(temp);
            return item;
        }

        prevnode = temp;

        temp = temp->next;
    }

    printf("\nValue %d not found\n", item);

    return INT_MIN;
}

void displayOperation(){
    NODE *temp;

    if(root == NULL){
        printf("\nLinked List Emtpy.\n");
        return ;
    }
    printf("\nThe Linked List is: \n");
    temp = root;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}