#include <cstdio>

int map[52][52];
bool visited[52][52];

int W, H, solve = 0;

int altX[8] = {1, -1, 0, 0, 1, 1, -1, -1};
int altY[8] = {0, 0, 1, -1, 1, -1, 1, -1};

bool safe(int x, int y)
{
    if(x < 0 || x >= H || y < 0 || y >= W) return 0;
    if(map[x][y] == 0) return 0;
    if(visited[x][y]) return 0;
    return 1;
}

void dfs(int x, int y)
{
    visited[x][y] = 1;
    for(int i = 0; i < 8; i++)
    {
        int X = x + altX[i], Y = y + altY[i];

        if(safe(X, Y))
            dfs(X, Y);
    }
}

int main(void)
{
    while(1)
    {
        scanf("%d %d", &W, &H);
        
        if(!W && !H) return 0;

        for(int i = 0; i < H; i++)
            for(int j = 0; j < W; j++)
                scanf("%d", &map[i][j]);
        
        for(int i = 0; i < H; i++)
            for(int j = 0; j < W; j++)
                if(!visited[i][j] && map[i][j] == 1)
                {
                    solve += 1;
                    dfs(i, j);
                }
        printf("%d\n", solve);

        // 초기화
        for(int i = 0; i < H; i++)
            for(int j = 0; j < W; j++)
                visited[i][j] = false;
        solve = 0;
    }
}