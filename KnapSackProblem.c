#include<stdio.h>
#include<stdlib.h>

typedef struct s{
    int jobID;
    float price;
    float weight;
    float rate;
    float solution;
}JOB;

// function prototypes
float KnapSack(JOB *, int, float);

int main(){
    int n, i, j;
    JOB *job, temp;;
    float maxProfit, capacity;

    printf("Enter number of jobs: ");
    scanf("%d", &n);

    job = (JOB *)malloc(n * sizeof(JOB));

    printf("Enter job id's: ");
    for(i=0;i<n;i++){
        scanf("%d", &job[i].jobID);
    }

    printf("Enter price: ");
    for(i=0;i<n;i++){
        scanf("%f", &job[i].price);
    }

    printf("Enter weights: ");
    for(i=0;i<n;i++){
        scanf("%f", &job[i].weight);
    }

    printf("Enter capacity: ");
    scanf("%f", &capacity);

    // initialise solution set to 0
    for(i=0;i<n;i++){
        job[i].solution = 0.0;
    }

    maxProfit = KnapSack(job, n, capacity);

    // sort the jobs in original order
    i = 1;
    while(i<n){
        j = i -1;
        temp = job[i];

        while(1){
            if(j==-1 || job[j].jobID <= temp.jobID){
                job[j+1] = temp;
                break;
            }
            else{
                job[j+1] = job[j];
            }

            j--;
        }

        i++;
    }
    
    printf("\nMaximum Profit Obtained: %f", maxProfit);
    printf("\nSolution Set: \n");
    for(i=0;i<n;i++){
        printf("%f ", job[i].solution);
    }

    return 0;
}

float KnapSack(JOB *job, int n, float capacity){
    int i, j;
    JOB temp;
    float weightGiven=0.0, maxProfit=0.0;

    // find rate=price/weight of the jobs
    for(i=0;i<n;i++){
        job[i].rate = job[i].price / job[i].weight;
    }

    // sort jobs according to descending order of rates
    for(i=0;i<n;i++){
        for(j=0;j<n-i-1;j++){
            if(job[j].rate < job[j+1].rate){
                temp = job[j];
                job[j] = job[j+1];
                job[j+1] = temp;
            }
        }
    }

    // implementing the knapsack algorithm
    i = 0;
    while(i<n && weightGiven<capacity){
        if(weightGiven+job[i].weight <= capacity)
            job[i].solution = 1;
        else
            job[i].solution = (capacity - weightGiven)/job[i].weight;
        
        weightGiven += job[i].solution * job[i].weight;
        maxProfit += job[i].solution * job[i].price;

        i++;
    }

    return maxProfit;
}