// implement job sequencing with deadlines problem

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// structure definition
typedef struct s{
    int jobID;
    float cost;
    int deadline;
}node;

// function prototype
void input(node*, int);
float solve(node*, int);
 
int main(){
    int n, i;
    node *a;
    float maxCost;

    printf("Enter number of jobs: ");
    scanf("%d", &n);

    a = (node*)malloc(n * sizeof(node));

    input(a, n);

    maxCost = solve(a, n);
    
    printf("The maximum cost is: %f", maxCost);

    return 0;
}

void input(node *a, int n){
    int i;
    
    printf("Enter job ID's: ");
    for(i=0;i<n;i++){
        scanf("%d", &a[i].jobID);
    }

    printf("Enter job costs: ");
    for(i=0;i<n;i++){
        scanf("%f", &a[i].cost);
    }

    printf("Enter job deadlines: ");
    for(i=0;i<n;i++){
        scanf("%d", &a[i].deadline);
    }
}

float solve(node *a, int n){
    int maxTime=-1;
    int i, j;
    int *timeslot;
    int fillSlot=0;
    int index;
    int jobID;
    float price = 0.0;
    node temp;

    // find maximum deadline time
    for(i=0;i<n;i++){
        if(maxTime < a[i].deadline){
            maxTime = a[i].deadline;
        }
    }

    timeslot = (int*)malloc(maxTime * sizeof(int));

    // initialise timeslot to -1. -1=>empty
    for(i=0;i<maxTime;i++){
        timeslot[i] = -1;
    }

    // bubble sort in desc order acc. to cost
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if(a[j].cost < a[j+1].cost){
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }

    // main algorithm
    for(i=0;i<n;i++){
        index = a[i].deadline - 1;

        while(index >= 0){
            if(timeslot[index] == -1){
                timeslot[index] = a[i].jobID;
                fillSlot++;
                break;
            }

            index--;
        }
        if(fillSlot == maxTime)
            break;
    }

    // calculating the total profit
    for(i=0;i<maxTime;i++){
        jobID = timeslot[i];

        for(j=0;j<n;j++){
            if(jobID == a[j].jobID){
                price += a[j].cost;
            }
        }
    }

    return price;
}