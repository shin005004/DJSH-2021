#include <stdio.h>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int N, M, H;
int map[101][101][101];
int visited[101][101][101];
int altX[6] = {0, 0, 1, -1, 0, 0};
int altY[6] = {1, -1, 0, 0, 0, 0};
int altZ[6] = {0, 0, 0, 0, 1, -1};

struct point{
    int x;
    int y;
    int z;
};

queue<point> q;

int safe(int x, int y, int z)
{
	if(x < 0 || y < 0 || z < 0) return 0;
	if(x >= N || y >= M || z >= H) return 0;
	if(visited[x][y][z] || map[x][y][z] != 0) return 0;
	return 1;
}

int solve(void)
{
	int max = 0;
	for(int i = 0; i < N; i++)
		for(int j = 0; j < M; j++)
            for(int k = 0; k < H; k++)
		    {
			    if(map[i][j][k] == 0)
			    	return 0;
			    if(max < visited[i][j][k]) 
                    max = visited[i][j][k];
		    }
	return max;
}

int main(void)
{
	scanf("%d %d %d", &M, &N, &H);
	
	for(int k = 0; k < H; k++)
		for(int i = 0; i < N; i++)
            for(int j = 0; j < M; j++)
            {
			    scanf("%d", &map[i][j][k]);
			    if(map[i][j][k] == 1)
                {
                    q.push({i, j, k});
                    visited[i][j][k] = 1;
                }
		    }
	
	while(!q.empty())
	{
		int x = q.front().x, y = q.front().y, z = q.front().z;
        q.pop();
		
        for(int i = 0; i < 6; i++)
        {
            int X = x + altX[i], Y = y + altY[i], Z = z + altZ[i];
            if(safe(X, Y, Z))
            {
                q.push({X, Y, Z});
                visited[X][Y][Z] = visited[x][y][z] + 1;
                map[X][Y][Z] = 1;
            }
        }
        
	}
	
	printf("%d\n", solve() - 1);
}