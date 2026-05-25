#include <stdio.h>
#include <stdbool.h>

bool isSafe(int N, int board[N][N], int row, int col)
{
    int i, j;

    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;

    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    for (i = row, j = col; i < N && j >= 0; i++, j--)
        if (board[i][j])
            return false;

    return true;
}

bool solveNQUtil(int N, int board[N][N], int col)
{
    if (col >= N)
        return true;

    for (int i = 0; i < N; i++) {

        if (isSafe(N, board, i, col)) {

            board[i][col] = 1;

            if (solveNQUtil(N, board, col + 1))
                return true;

            board[i][col] = 0;
        }
    }

    return false;
}

void printSolution(int N, int board[N][N])
{
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

void solveNQ(int N)
{
    int board[N][N];

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            board[i][j] = 0;

    if (solveNQUtil(N, board, 0) == false) {
        printf("Solution does not exist\n");
        return;
    }

    printSolution(N, board);
}

int main()
{
    int N;

    printf("Enter value of N: ");
    scanf("%d", &N);

    if (N <= 0) {
        printf("Enter a positive number.\n");
        return 0;
    }

    solveNQ(N);

    return 0;
}
