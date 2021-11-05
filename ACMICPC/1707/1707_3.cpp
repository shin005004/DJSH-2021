// wrong
#include <cstdio>
#include <vector>
#include <iostream>
#include <cstring>
// #include <queue>
using namespace std;

vector<int> node[20005];
int visited[20005];
int K, V, E;

void dfs(int x, int id)
{
    int otherId = id == 1 ? 2 : 1;
    visited[x] = id;
    for(int i = 0; i < node[x].size(); i++)
    {
        int to = node[x][i];
        if(!visited[to])
            dfs(to, otherId);
    }
}

bool isBipartiteGraph(){
    for(int i = 1; i <= V; i++)
    {
        for(int j = 0; j < node[i].size(); j++)
        {
            int next = node[i][j];
            if(visited[i] == visited[next])
                return 0;
        }
    }
    return 1;
}

int main(void)
{
    scanf("%d", &K);
    while(K--)
    {
        scanf("%d %d", &V, &E);
        for(int i = 1; i <= E; i++)
        {
            int a, b;
            scanf("%d %d", &a, &b);

            node[a].push_back(b);
            node[b].push_back(a);
        }
        for(int i = 1; i <= V; i++)
            if(!visited[i])
                dfs(i, 1);

        printf("%s\n", (isBipartiteGraph()) ? "YES" : "NO");

        memset(visited, false, sizeof(visited));
        for(int i = 0; i <= V; i++)
            node[i].clear();
    }
    
}