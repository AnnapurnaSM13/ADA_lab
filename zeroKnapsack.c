#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int zeroOrOne_Knapsack(int n, int val[], int w[], int c)
{
    int a[50][50];

    for (int i = 0; i <= n; i++)
        a[i][0] = 0;

    for (int j = 0; j <= c; j++)
        a[0][j] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= c; j++) {
            if (w[i-1] > j)
                a[i][j] = a[i-1][j];
            else
                a[i][j] = max(
                    a[i-1][j],
                    val[i-1] + a[i-1][j - w[i-1]]
                );
        }
    }

    return a[n][c];
}

int main()
{
    int val[20], w[20], c, n;

    printf("Enter number of items: ");
    scanf("%d", &n);

    printf("Enter values:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &val[i]);
    }

    printf("Enter weights:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &w[i]);
    }

    printf("Enter capacity: ");
    scanf("%d", &c);

    int result = zeroOrOne_Knapsack(n, val, w, c);
    printf("Maximum value = %d\n", result);

    return 0;
}
