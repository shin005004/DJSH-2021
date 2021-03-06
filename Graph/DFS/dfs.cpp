#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
vector<int> a[1000];
bool check[1000];

void dfs(int node)
{
    check[node] = true;
    printf("%d ", node);
    for(int i = 0; i < a[node].size(); i++)
    {
        int next = a[node][i];
        if(check[next] == false)
        {
            dfs(next);
        } 
    }
}

int bfs(int start)
{
    queue<int> q;
    memset(check, false, sizeof(check));
    check[start] = true;

    q.push(start);
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        printf("%d ", node);

        for(int i = 0; i < a[node].size(); i++)
        {
            int next = a[node][i];
            if(check[next] == false)
            {
                check[next] = true;
                q.push(next);
            }
        }
    }
    printf("\n");
}

int main(void)
{
    int n, m, start;
    scanf("%d %d %d", &n, &m, &start);
    for(int i = 0; i < m; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        a[u].push_back(v);
        a[v].push_back(u);
    }

    dfs(start);
    printf("\n");
    bfs(start);
}