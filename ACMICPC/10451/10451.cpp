#include <cstdio>

int link[1005];
int visited[1005];
int N, T, count = 0;

void dfs(int x)
{
    visited[x] = true;
    if(visited[link[x]])
        return;
    dfs(link[x]);
}

int main(void)
{
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &N);
        count = 0;
        for(int i = 1; i <= N; i++)
            scanf("%d", &link[i]);
        
        for(int i = 1; i <= N; i++)
        {
            if(!visited[i])
            {
                dfs(i);
                count += 1;
            }
        }
        for(int i = 0; i < 1005; i++)
            visited[i] = false;
        

        printf("%d\n", count);
    }
    
}