#include <stdio.h>
#include <vector>
using namespace std;

vector<int> node[101];
bool visited[101];
int N, M, count = 0;

void dfs(int id)
{
    visited[id] = true;
    for(int i = 0; i < node[id].size(); i++)
    {
        if(!visited[node[id][i]])
        {
            dfs(node[id][i]);
            count++;
        }
    }
}

int main(void)
{
    scanf("%d", &N);
    scanf("%d", &M);

    for(int i = 0; i < M; i++)
    {
        int a, b;

        scanf("%d %d", &a, &b);
        node[a].push_back(b);
        node[b].push_back(a);
    }

    dfs(1);
    printf("%d\n", count);
    return 0;
}
