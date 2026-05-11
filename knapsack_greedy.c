#include <stdio.h>

int n, m;
float x[100], p[100], w[100];

void sort() {
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            if((p[i] / w[i]) < (p[j] / w[j])) {
                float temp1,temp2;

                temp1 = p[i];
                p[i] = p[j];
                p[j] = temp1;

                temp2 = w[i];
                w[i] = w[j];
                w[j] = temp2;
            }
        }
    }
}

float greedy_ks(int m, int n) {
    int i;

    for(i = 0; i < n; i++) {
        x[i] = 0;
    }

    float rem_cap = m;

    for(i = 0; i < n; i++) {
        if(w[i] > rem_cap)
            break;

        x[i] = 1.0;
        rem_cap = rem_cap - w[i];
    }

    if(i < n) {
        x[i] = rem_cap / w[i];
    }

    float sum = 0;
    for(i = 0; i < n; i++) {
        sum += p[i] * x[i];
    }

    return sum;
}

int main() {
    printf("Enter the value of n: ");
    scanf("%d", &n);

    printf("Enter n profits:\n");
    for(int i = 0; i < n; i++) {
        scanf("%f", &p[i]);
    }

    printf("Enter n weights:\n");
    for(int i = 0; i < n; i++) {
        scanf("%f", &w[i]);
    }

    printf("Enter maximum capacity of knapsack: ");
    scanf("%d", &m);

    sort();

    float sum = greedy_ks(m, n);

    printf("Maximum profit: %f\n", sum);

    return 0;
}
