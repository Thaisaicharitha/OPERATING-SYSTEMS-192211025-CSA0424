#include <stdio.h>

#define N 3   

int main() {
    int i, j;
    int available[N] = {1, 2, 0};   
    int max[N][N] = {{3, 6, 8}, {4, 3, 3}, {3, 4, 4}};   
    int allocation[N][N] = {{3, 3, 3}, {2, 0, 3}, {1, 2, 4}};   
    int need[N][N];   
    int work[N];   
    int finish[N] = {0};   
    int deadlock = 1;   

    
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }
    for (i = 0; i < N; i++) {
        work[i] = available[i];
    }

    for (i = 0; i < N; i++) {
        if (!finish[i]) {
            int safe = 1;
            for (j = 0; j < N; j++) {
                if (need[i][j] > work[j]) {
                    safe = 0;
                    break;
                }
            }
            if (safe) {
                finish[i] = 1;
                for (j = 0; j < N; j++) {
                    work[j] += allocation[i][j];
                }
                deadlock = 0;   
            }
        }
    }

    
    if (deadlock) {
        printf("System is in deadlock state.\n");
        printf("Deadlocked processes: ");
 for (i = 0; i < N; i++) {
            if (!finish[i]) {
                printf("%d ", i);
            }
        }
        printf("\n");
    } else {
        printf("System is not in deadlock state.\n");
    }
return 0;
}
