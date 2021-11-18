#include <cstdio>

int parent[1000001];

int Find(int x)
{
    if(x == parent[x])
        return x;
    return parent[x] = Find(parent[x]);
}

void Union(int x, int y)
{
    x = Find(x);
    y = Find(y);
    if(x != y)
        parent[y] = x;
}

int N, M;
int main(void)
{
    scanf("%d %d", &N, &M);
    for(int i = 0; i <= N; i++)
        parent[i] = i;
    for(int i = 0; i < M; i++)
    {
        int k, a, b;
        scanf("%d %d %d", &k, &a, &b);
        if(k == 0)
            Union(a, b);
        else
            printf(Find(a) == Find(b) ? "Yes\n" : "NO\n");
    }
    return 0;
}