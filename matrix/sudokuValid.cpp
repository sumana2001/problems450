#include <bits/stdc++.h>
using namespace std;
#define N 9

bool isInRange(int board[][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (board[i][j] < 0 || board[i][j] > 9)
                return false;
        }
    }
    return true;
}

bool sudokuValid(int board[][N])
{
    if (!isInRange(board))
        return false;
    bool unique[N + 2];
    for (int i = 0; i < N; i++)
    {
        memset(unique, false, sizeof(unique));
        for (int j = 0; j < N; j++)
        {
            int Z = board[i][j];
            if (unique[Z] && Z != 0)
                return false;
            unique[Z] = true;
        }
    }
    for (int i = 0; i < N; i++)
    {
        memset(unique, false, sizeof(unique));
        for (int j = 0; j < N; j++)
        {
            int Z = board[j][i];
            if (unique[Z] && Z != 0)
                return false;
            unique[Z] = true;
        }
    }
    for (int i = 0; i < N - 2; i += 3)
    {
        for (int j = 0; j < N - 2; j += 3)
        {
            memset(unique, false, sizeof(unique));
            for (int k = 0; k < 3; k++)
            {
                for (int l = 0; l < 3; l++)
                {
                    int X = i + k;
                    int Y = j + l;
                    int Z = board[X][Y];
                    if (unique[Z] && Z != 0)
                        return false;
                    unique[Z] = true;
                }
            }
        }
    }
    return true;
}

int main()
{
    int board[N][N] = {{3, 0, 6, 5, 0, 8, 4, 0, 0},
                       {5, 2, 0, 0, 0, 0, 0, 0, 0},
                       {0, 8, 7, 0, 0, 0, 0, 3, 1},
                       {0, 0, 3, 0, 1, 0, 0, 8, 0},
                       {9, 0, 0, 8, 6, 3, 0, 0, 5},
                       {0, 5, 0, 0, 9, 0, 6, 0, 0},
                       {1, 3, 0, 0, 0, 0, 2, 5, 0},
                       {0, 0, 0, 0, 0, 0, 0, 7, 4},
                       {0, 0, 5, 2, 0, 6, 3, 0, 0}};
    if (sudokuValid(board))
        cout << "Valid" << endl;
    else
        cout << "Not Valid" << endl;
    return 0;
}