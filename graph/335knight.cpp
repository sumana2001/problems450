#include <bits/stdc++.h>
using namespace std;
int n = 6;
int visited[6][6];

bool isSafe(int x, int y)
{
    if (x >= 0 && x < n && y >= 0 && y < n)
        return true;
    return false;
}

int knight(int kx, int ky, int tx, int ty)
{
    int dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
    int dy[] = {-1, -2, -2, -1, 1, 2, 2, 1};
    queue<pair<int, int> > q;
    q.push(make_pair(kx, ky));
    visited[kx][ky] = 0;
    while (!q.empty())
    {
        pair<int, int> temp = q.front();
        q.pop();
        if (temp.first == tx && temp.second == ty)
            return visited[temp.first][temp.second];
        for (int i = 0; i < n; i++)
        {
            int x = temp.first + dx[i];
            int y = temp.second + dy[i];
            if (isSafe(x, y) && visited[x][y] == -1)
            {
                visited[x][y] = visited[temp.first][temp.second] + 1;
                q.push(make_pair(x, y));
            }
        }
    }
    return -1;
}

int main()
{
    int kx = 4, ky = 5, tx = 1, ty = 1;
    memset(visited, -1, sizeof(visited));
    cout << knight(kx, ky, tx, ty) << endl;
    return 0;
}