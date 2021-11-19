// failed

#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;

int map[101][101], visited[101][101];
int solveVisited[101][101];
int countLand = 0, N;

int ax[4] = {0, 0, 1, -1};
int ay[4] = {1, -1, 0, 0};

bool safe(int x, int y)
{    return 0 <= x && x < N && 0 <= y && y < N;    }

int dfs(int x, int y, int id)
{
    visited[x][y] = id;
    for(int i = 0; i < 4; i++)
    {
        int X = x + ax[i], Y = y + ay[i];
        if(!visited[X][Y] && safe(X, Y) && map[X][Y])
            dfs(X, Y, id);
    }
    return 0;
}

int bfs(int id)
{
    queue<pair<int, int>> q;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            if(visited[i][j] == id)
            {
                solveVisited[i][j] = 1;
                q.push({i, j});
            }
        
    int solve = 0;
    while(!q.empty())
    {
        int S = q.size();
        for(int s = 0; s < S; s++)
        {
            pair<int, int> cur = q.front();
            q.pop();

            for(int i = 0; i < 4; i++)
            {
                int x = cur.first + ax[i];
                int y = cur.second + ay[i];
                if(safe(x, y))
                {
                    if(visited[x][y] != id && visited[x][y] != 0)
                    {
                        return solve;
                    }
                    if(visited[x][y] == 0 && !solveVisited[x][y])
                    {
                        solveVisited[x][y] = 1;
                        q.push({x, y});
                    }
                }
                    
            }

        }
        solve++;
    }
}

int main(void)
{
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            scanf("%d", &map[i][j]);
    
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            if(!visited[i][j] && map[i][j])
                dfs(i, j, ++countLand);
    
    int answer = 987654321;
    for(int id = 1; id <= countLand; id++)
    {
        int temp = bfs(id);
        answer = answer > temp ? temp : answer;
        memset(solveVisited, false, sizeof(solveVisited));
        // printf("%d\n", temp);
    }
    printf("%d\n", answer);
    return 0;
}