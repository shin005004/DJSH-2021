// dfs and bfs
#include <cstdio>
#include <queue>
using namespace std;

int graph[1005][1005];
bool visited[1005];

int N, M, V;

void dfs(int id)
{
    printf("%d ", id);
    visited[id] = true;

    for(int i = 1; i <= N; i++)
    {
        int to = graph[id][i];
        if(!visited[i] && to != 0)
            dfs(i);
    }
}

void bfs(int v)
{
    queue<int> q;
    visited[v] = true;
    q.push(v);
    while(!q.empty())
    {
        int id = q.front();
        q.pop();
        
        printf("%d ", id);

        for(int i = 1; i <= N; i++)
        {
            int to = graph[id][i];
            if(!visited[i] && to != 0)
            {
                visited[i] = true;
                q.push(i);
            }
        }
    }
}

int main(void)
{
    scanf("%d %d %d", &N, &M, &V);

    for(int i = 0; i < M; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);

        graph[a][b] = graph[b][a] = 1;
    }

    dfs(V);
    printf("\n");
    for(int i = 1; i <= N; i++)
        visited[i] = false;
    bfs(V);
    return 0;
}