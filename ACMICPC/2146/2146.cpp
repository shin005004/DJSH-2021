#include <cstdio>
#include <queue>
using namespace std;

int map[101][101];
int visited[101][101];
int count = 0;

int ax[4] = {0, 0, 1, -1};
int ay[4] = {1, -1, 0, 0};

int dfs(int x, int y, int id)
{
    visited[x][y] = id;
    for(int i = 0; i < 4; i++)
    {
        int X = x + ax[i], Y = y + ay[i];
        if(!visited[X][Y] && )
    }
}

int N;
int main(void)
{
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            scanf("%d", &map[i][j]);
    
    queue<pair<int, int>> q;
       
}