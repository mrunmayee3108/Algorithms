#include <stdio.h>

int main(){
    int n, i, j, maxdeadline = 0, tempp, tempd, tempi;
    printf("Enter the number of jobs: ");
    scanf("%d", &n);
    int jobID[n], profit[n], deadline[n];
    printf("Enter jobID, profit and deadline for each job\n");

    for(i = 0; i < n; i++){
        scanf("%d %d %d", &jobID[i], &profit[i], &deadline[i]);
        if(deadline[i] > maxdeadline){
            maxdeadline = deadline[i];
        }
    }

    for(i = 0; i < n - 1; i++){
        for(j = 0; j < n - i - 1; j++){
            if(profit[j] < profit[j + 1]){
                tempp = profit[j];
                profit[j] = profit[j + 1];
                profit[j + 1] = tempp;

                tempd = deadline[j];
                deadline[j] = deadline[j + 1];
                deadline[j + 1] = tempd;

                tempi = jobID[j];
                jobID[j] = jobID[j + 1];
                jobID[j + 1] = tempi;
            }
        }
    }

    int slot[maxdeadline];
    int seq[maxdeadline];
    int totalprofit = 0;

    for(i = 0; i < maxdeadline; i++){
        slot[i] = 0;
        seq[i] = -1; 
    }

    for(i = 0; i < n; i++){
        if (deadline[i] <= 0) continue;              
        for(j = deadline[i]-1; j >= 0; j--){
            if(slot[j] == 0){
                slot[j] = 1;
                seq[j] = jobID[i];
                totalprofit += profit[i];
                break;
            }
        }
    }

    printf("Obtained job sequence:\n");
    for(i = 0; i < maxdeadline; i++){
        if(slot[i] == 1){
            printf("%d ", seq[i]);
        }
    }
    printf("\nTotal profit: %d\n", totalprofit);
    return 0;
}


