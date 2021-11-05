// 초기화 까먹는 실수를 함
// visited 와 node 모두 초기화 해야한다는 것을 잊지 말자
#include <cstdio>
#include <vector>
#include <iostream>
#include <cstring>
// #include <queue>
using namespace std;

vector<int> node[20005];
int visited[20005];
int solve = 1;

void dfs(int x, int id)
{
    int otherId = id == 1 ? 2 : 1;
    visited[x] = id;
    for(int i = 0; i < node[x].size(); i++)
    {
        int to = node[x][i];
        if(!visited[to])
            dfs(to, otherId);
        else{
            // adjacent verticies should be different id's
            if(visited[to] == id)
                solve = 0;
        }
    }
}

int K, V, E;
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
            
        memset(visited, false, sizeof(visited));
        for(int i = 1; i <= V; i++)
            node[i].clear();

        printf("%s\n", (solve) ? "YES" : "NO");
        solve = 1;
    }
    
}