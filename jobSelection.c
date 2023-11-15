#include <stdio.h>
#include <stdlib.h>

void swap(float *a, float *b) {
    float temp = *a;
    *a = *b;
    *b = temp;
}

void print(float *arr, int n) {
    for (int i = 0; i < n; ++i) {
        printf("%f\t", arr[i]);
    }
    printf("\n");
}

int findmax(int *deadline, int n) {
    int max = deadline[0];
    for (int i = 0; i < n; i++) {
        if (deadline[i] > max)
            max = deadline[i];
    }
    return max;
}

int main() {
    int n = 5;
    char jobs[] = {'1', '2', '3', '4', '5'};
    float profits[] = {10, 5, 20, 15, 17};
    int deadline[] = {1, 2, 3, 1, 1};

    // Sort jobs in descending order of profits
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (profits[j] < profits[j + 1]) {
                swap(&profits[j], &profits[j + 1]);
                //swap(&deadline[j], &deadline[j + 1]);
                int temp1=deadline[j];
                deadline[j]=deadline[j+1];
                deadline[j+1]=temp1;
                char temp = jobs[j];
                jobs[j] = jobs[j + 1];
                jobs[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < n; i++)
        printf("%c\t\t", jobs[i]);
    printf("\n");
    print(profits, n);
    for (int i = 0; i < n; i++)
        printf("%d\t\t", deadline[i]);

    int maxDeadline = findmax(deadline, n);
    char ans[maxDeadline];

    for (int i = 0; i < maxDeadline; i++)
        ans[i] = '0';
    float profit=1;
    for (int i = 0; i < n; i++) {
        for (int j = deadline[i] - 1; j >= 0; j--) {
            if (ans[j] == '0') {
                ans[j] = jobs[i];
                profit+=profits[i];
                break;
            }
        }
    }
    printf("\n%lf\n",profit);
    for (int i = 0; i < maxDeadline; i++)
        printf("%c ", ans[i]);

    return 0;
}
