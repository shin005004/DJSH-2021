#include <cstdio>
#include <vector>
#include <iostream>
// #include <queue>
using namespace std;

vector<int> node[100005];
int parent[100005];
bool check[100005];

void dfs(int from, int id)
{
    parent[id] = from;
    check[id] = true;
    for(int i = 0; i < node[id].size(); i++)
    {
        int to = node[id][i];
        if(!check[to])
        {
            dfs(id, to);
        }
    }
}

int N;
int main(void)
{
    scanf("%d", &N);
    for(int i = 1; i < N; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);

        node[a].push_back(b);
        node[b].push_back(a);
    }

    // for(int i = 1; i <= N; i++)
    // {
    //     for(int j = 0; j < node[i].size(); j++)
    //     {
    //         printf("%d ", node[i][j]);
    //     }
    //     printf("\n");
    // }

    dfs(1, 1);
    for(int i = 2; i <= N; i++)
        printf("%d\n", parent[i]);
}