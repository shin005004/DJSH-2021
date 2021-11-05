#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector<pair<int, int>> node[100005];
bool visited[100005];
int maxHeight = 0, maxNode = 1;

void dfs(int id, int height)
{
    if (height > maxHeight)
    {
         maxHeight = height;
         maxNode = id;
    }
    visited[id] = true;

    for(int i = 0; i < node[id].size(); i++)
    {
        int to = node[id][i].first;
        if(!visited[to])
            dfs(to, height + node[id][i].second);
    }
}

int V;
int main(void)
{
    scanf("%d", &V);
    for(int i = 0; i < V; i++)
    {
        int id;
        cin >> id;

        while(1)
        {
            int a, b;
            cin >> a;

            if(a == -1) break;
            cin >> b;

            node[id].emplace_back(a, b);
            // printf(" %d %d %d\n", id, a, b);
        }
    }
    dfs(1, 0);
    // memset 으로 초기화 해주는 걸 계속 까먹고 있음
    memset(visited, false, sizeof(visited));
    maxHeight = 0;
    dfs(maxNode, 0);
    printf("%d\n", maxHeight);
}