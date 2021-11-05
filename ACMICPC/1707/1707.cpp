// timeout
#include <cstdio>
#include <vector>
#include <iostream>
// #include <queue>
using namespace std;

vector<int> node[20005];
int K, V, E;

bool isAdjacent(int x, int y)
{
    for(int i = 0; i < node[x].size(); i++)
        if(node[x][i] == y)
            return true;
    return false;
}

int l[20005], r[20005];
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

        for(int i = 0; i < 20005; i++)
        {
            l[i] = 1;
            r[i] = 0;
        }

        for(int i = 1; i <= V; i++)
        {
            if(!l[i]) continue;

            for(int j = i + 1; j < V; j++)
            {
                if(isAdjacent(i, j) && l[j])
                {
                    l[j] = 0;
                    r[j] = 1;
                }
            }
        }

        int solve = 1;
        for(int i = 1; i <= V; i++)
        {
            if(!r[i]) continue;

            for(int j = i + 1; j < V; j++)
                if(isAdjacent(i, j) && r[j])
                    solve = 0;
        }

        printf("%s\n", solve ? "YES" : "NO");
    }
    
}