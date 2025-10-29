#include<stdio.h>
void merge(float ratio[], int profit[], int weight[], int start, int mid, int end) {
    int leftSize = mid - start + 1;
    int rightSize = end - mid;
    float leftRatio[leftSize];
    int leftProfit[leftSize], leftWeight[leftSize];
    
    float rightRatio[rightSize];
    int rightProfit[rightSize], rightWeight[rightSize];

    for(int i = 0; i < leftSize; i++) {
        leftRatio[i] = ratio[start + i];
        leftProfit[i] = profit[start + i];
        leftWeight[i] = weight[start + i];
    }
    
    for(int i = 0; i < rightSize; i++) {
        rightRatio[i] = ratio[mid + 1 + i];
        rightProfit[i] = profit[mid + 1 + i];
        rightWeight[i] = weight[mid + 1 + i];
    }

    int leftIndex = 0, rightIndex = 0, mainIndex = start;
    
    while(leftIndex < leftSize && rightIndex < rightSize) {
        if(leftRatio[leftIndex] >= rightRatio[rightIndex]) {
            ratio[mainIndex] = leftRatio[leftIndex];
            profit[mainIndex] = leftProfit[leftIndex];
            weight[mainIndex] = leftWeight[leftIndex];
            leftIndex++;
        } else {
            ratio[mainIndex] = rightRatio[rightIndex];
            profit[mainIndex] = rightProfit[rightIndex];
            weight[mainIndex] = rightWeight[rightIndex];
            rightIndex++;
        }
        mainIndex++;
    }
    
    while(leftIndex < leftSize) {
        ratio[mainIndex] = leftRatio[leftIndex];
        profit[mainIndex] = leftProfit[leftIndex];
        weight[mainIndex] = leftWeight[leftIndex];
        leftIndex++;
        mainIndex++;
    }
    
    while(rightIndex < rightSize) {
        ratio[mainIndex] = rightRatio[rightIndex];
        profit[mainIndex] = rightProfit[rightIndex];
        weight[mainIndex] = rightWeight[rightIndex];
        rightIndex++;
        mainIndex++;
    }
}

void mergeSort(float ratio[], int profit[], int weight[], int start, int end) {
    if(start < end) {
        int mid = start + (end - start) / 2;
        mergeSort(ratio, profit, weight, start, mid);
        mergeSort(ratio, profit, weight, mid + 1, end);
        merge(ratio, profit, weight, start, mid, end);
    }
}

int main(){
    int n, W, i, j, tempp, tempw;
    float tempr;
    
    printf("Enter the number of items: ");
    scanf("%d", &n);
    printf("Enter the maximum capacity of the knapsack: ");
    scanf("%d", &W);
    
    int profit[n], weight[n];
    float ratio[n];
    
    for(i=0; i<n; i++){
        printf("Enter the profit and weight of item %d: ", i+1);
        scanf("%d %d", &profit[i], &weight[i]);
        ratio[i] = (float) profit[i]/weight[i];
    }
    // for(i=0; i<n-1; i++){
    //     for(j=0; j<n-i-1; j++){
    //         if(ratio[j]<ratio[j+1]){
    //             tempr = ratio[j];
    //             ratio[j] = ratio[j+1];
    //             ratio[j+1] = tempr;
                
    //             tempp = profit[j];
    //             profit[j] = profit[j+1];
    //             profit[j+1] = tempp;
                
    //             tempw = weight[j];
    //             weight[j] = weight[j+1];
    //             weight[j+1] = tempw;
    //         }
    //     }
    // }
    mergeSort(ratio, profit, weight, 0, n-1);
    
    float totalprofit = 0, capacity = W;
    
    for(i=0; i<n; i++){
        if(weight[i]<=capacity){
            totalprofit+=profit[i];
            capacity-=weight[i];
        }else{
            totalprofit+=ratio[i]*capacity;
            break;
        }
    }
    printf("Maximum profit in knapsack = %0.2f", totalprofit);
    return 0;
}

