#include <bits/stdc++.h>
using namespace std;

vector<int>v[1001];
int check[10001];

void DFS(int u)
{
    check[u] = 1;
    for(int x : v[u])
    {
        if(!check[x])
        {
            DFS(x);
        }
    }
}

int main()
{
    int n , m ; cin >> n >> m;
    for(int i = 1 ; i <= m ; i++)
    {
        int a , b ; cin >> a >> b;
        v[a].push_back(b);
    }
    for(int i = 1 ; i <= n ; i++)
    {
        memset(check , 0 , sizeof(check));
        DFS(i);
        for(int j = 1 ; j <= n ;j++)
        {
            if(!check[j])
            {
                cout << 0;
                return 0;
            }
        }
    }
    cout << 1;
}
