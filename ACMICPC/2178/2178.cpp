#include <cstdio>
#include <queue>
#include <iostream>
using namespace std;

queue<pair<int, int>> q;
char map[101][101];
int visited[101][101];
int altX[4] = {0, 1, -1, 0};
int altY[4] = {1, 0, 0, -1};
int N, M;

int main(void)
{
    // N 세로, M 가로
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++)
        scanf("%s", map[i]);
    
    q.push({0, 0});
    visited[0][0] = 1;
    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        // printf("%d %d\n", x, y);
        q.pop();
        for(int i = 0; i < 4; i++)
        {
            int newX = x + altX[i], newY = y + altY[i];
            if(newX < N && newX >= 0 && newY < M && newY >= 0)
                if(map[newX][newY] == '1' && !visited[newX][newY])
                {
                    q.push({newX, newY});
                    visited[newX][newY] = visited[x][y] + 1;
                }
            // printf("%d %d\n", newX, newY);
        }
        
    }
    // for(int i = 0; i < N; i++)
    // {
    //     for(int j = 0; j < M; j++)
    //         printf("%d ", visited[i][j]);
    //     printf("\n");
    // }
    printf("%d\n", visited[N - 1][M - 1]);
}