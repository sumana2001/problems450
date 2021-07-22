#include <bits/stdc++.h>
using namespace std;
#define N 4

void rotate1(int mat[][N])
{
    for (int x = 0; x < N / 2; x++)
    {
        for (int y = x; y < N - x - 1; y++)
        {
            int temp = mat[x][y];
            mat[x][y] = mat[y][N - x - 1];
            mat[y][N - x - 1] = mat[N - 1 - x][N - 1 - y];
            mat[N - 1 - x][N - 1 - y] = mat[N - 1 - y][x];
            mat[N - 1 - y][x] = temp;
        }
    }
}

void rotate2(int mat[][N])
{
    for (int i = 0; i < N; i++)
        for (int j = i; j < N; j++)
            swap(mat[i][j], mat[j][i]);
    for (int i = 0; i < N; i++)
        for (int j = 0, k = N - 1; j < k; j++, k--)
            swap(mat[j][i], mat[k][i]);
}

void display(int mat[][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int mat[N][N] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}};
    rotate2(mat);
    display(mat);
    return 0;
}