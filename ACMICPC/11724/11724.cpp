#include <cstdio>
#include <vector>
#include <iostream>
// #include <queue>
using namespace std;

vector<int> node[1005];
int visited[1005];
int solve = 0;

void dfs(int x, int id)
{
    visited[x] = id;
    for(int i = 0; i < node[x].size(); i++)
    {
        int to = node[x][i];
        if(!visited[to])
        {
            dfs(to, id);
        }
    }
}

int N, M;
int main(void)
{
    scanf("%d %d", &N, &M);
    for(int i = 1; i <= M; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);

        node[a].push_back(b);
        node[b].push_back(a);
    }

    for(int i = 1; i <= N; i++)
    {
        if(!visited[i])
            dfs(i, ++solve);
    }
    printf("%d\n", solve);
}