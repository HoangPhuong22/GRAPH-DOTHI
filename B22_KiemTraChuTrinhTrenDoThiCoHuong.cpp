#include <bits/stdc++.h>
using namespace std;
const int maxn = 1001;
vector<int>v[maxn];
bool ok[maxn];
int color[maxn];
bool DFS(int s)
{
    color[s] = 1;
    for(int x : v[s])
    {
        if(!ok[x])
        {
            if(DFS(x)) return true;
        }
        else if(color[x] == 1) return true;
    }
    color[s] = 2;
}

int main()
{
    int n , m ; cin >> n >> m;
    for(int i = 1 ; i <= m ; i++)
    {
        int a , b ; cin >> a >> b;
        v[a].push_back(b);
    }
    for(int i = 1 ; i <= n ;i++)
    {
        if(!ok[i])
        {
            if(DFS(i , 0))
            {
                cout << 1;
                return 0;
            }
        }
    }
    cout << 0;
}
