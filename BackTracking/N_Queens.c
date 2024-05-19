#include <stdio.h>
#define N 4

void printSolution(int board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j])
                printf("Q ");
            else
                printf(". ");
        }
        printf("\n");
    }
    printf("\n");
}

int isSafe(int board[N][N], int row, int col) {
   int duprow=row;
    int dupcol=col;

    while(col>=0 && row>=0)
    {
        if(board[row][col]==1)
         return 0;
         col--;
         row--;
        
    }
col=dupcol;
row=duprow;
    while(col>=0 )
    {
        if(board[row][col]==1)
        {
            return 0;
        }
        col--;  
    }

    col=dupcol;
row=duprow;
    while(col>=0 && row<N)
    {
        if(board[row][col]==1)
        {
       return 0;
        }
          col--;
        row++;
    }

    return 1;

}

int queen(int board[N][N], int col) {
    if (col >= N) {
        printSolution(board);
        return 1;
    }

    int res = 0;
    for (int i = 0; i < N; i++) {
        if (isSafe(board, i, col)) {
            board[i][col] = 1;
            res = queen(board, col + 1) || res;
            board[i][col] = 0; // BACKTRACK
        }
    }

    return res;
}

void solve() {
    int board[N][N] = { { 0, 0, 0, 0 },
                        { 0, 0, 0, 0 },
                        { 0, 0, 0, 0 },
                        { 0, 0, 0, 0 } };

    if (queen(board, 0) == 0) {
        printf("Solution does not exist\n");
    }
}

int main() {
    solve();
    return 0;
}
