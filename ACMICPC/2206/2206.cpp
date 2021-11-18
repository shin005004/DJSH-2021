#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

int N, M;
char map[1001][1001];
int visited[1001][1001][2];
int ax[4] = {0, 0, 1, -1};
int ay[4] = {1, -1, 0, 0};

bool safe(int x, int y, int wall)
{
    if(wall)
        return (x > 0 && y > 0) && (x <= N && y <= M);
    return (x > 0 && y > 0) && (x <= N && y <= M) && map[x][y] == '0';
}

struct point{
    int x;
    int y;
    int wall;
};

int main(void)
{
    scanf("%d %d", &N, &M);
    for(int i = 1; i <= N; i++)
        scanf("%s", map[i] + 1);
    
    // <x, y, wall>
    queue<point> q;
    visited[1][1][1] = visited[1][1][0] = 1;
    q.push({1, 1, 1});
    while(!q.empty())
    {
        point cur = q.front();
        q.pop();
        if(cur.x == N && cur.y == M)
        {
            printf("%d\n", visited[cur.x][cur.y][cur.wall]);
            return 0;
        }

        for(int i = 0; i < 4; i++)
        {
            int x = cur.x + ax[i], y = cur.y + ay[i];
            // printf("%d %d\n", x, y);

            if(cur.wall == 1 && map[x][y] == '1' && safe(x, y, cur.wall) && !visited[x][y][0])
            {
                visited[x][y][0] = visited[cur.x][cur.y][cur.wall] + 1;
                q.push({x, y, 0});
            }
            if(map[x][y] == '0' && safe(x, y, cur.wall) && !visited[x][y][cur.wall])
            {
                visited[x][y][cur.wall] = visited[cur.x][cur.y][cur.wall] + 1;
                q.push({x, y, cur.wall});
            }
        }

        // for(int i = 1; i <= N; i++)
        // {
        //     for(int j = 1; j <= M; j++)
        //         printf("%d ", visited[i][j][0]);
        //     printf("\n");
        // }
        // printf("\n");
    }
    printf("-1\n");
    return 0;
}