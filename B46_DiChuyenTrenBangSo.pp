#include <bits/stdc++.h>
using namespace std;


int n, m;
int a[505][505];
int visited[1001][1001];

int dx[4] = {0, 0, -1, 1};
int dy[4] = { -1, 1, 0, 0};

struct cmp
{
    bool operator()(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b)
    {
        return a.second.second > b.second.second;
    }
};

int BFS()
{
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, cmp> pq;
    pq.push({1, {1, a[1][1]}});
    visited[1][1] = 1;
    while (pq.size() != 0)
    {
        pair<int, pair<int, int>> top = pq.top();
        pq.pop();
        for (int k = 0; k < 4; ++k)
        {
            int x = top.first + dx[k];
            int y = top.second.first + dy[k];
            if (x == n and y == m)
                return top.second.second + a[x][y];
            if (x >= 1 && x <= n && y >= 1 && y <= m && !visited[x][y])
            {
                visited[x][y] = 1;
                pq.push({x, {y, top.second.second + a[x][y]}});
            }
        }
    }
    return -1;
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            cin >> a[i][j];
        }
    }
    cout << BFS() << endl;
    return 0;
}
