#include <stdio.h>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int N, M;
int map[1005][1005];
int day[1005][1005];
bool v[1005][1005];

queue<pair<int, int> > q;

int safe(int y, int x)
{
	if(x < 0 || y < 0) return 0;
	if(x >= M || y >= N) return 0;
	if(v[y][x] || map[y][x] == -1) return 0;
	return 1;
}

int solve(void)
{
	int max = 0;
	for(int i = 0; i < N; i++)
		for(int j = 0; j < M; j++)
		{
			if(map[i][j] == 0)
				return -1;
			if(max < day[i][j]) max = day[i][j];
		}
	return max;
}

int main(void)
{
	scanf("%d %d", &M, &N);
	
	for(int i = 0; i < N; i++)
		for(int j = 0; j < M; j++)
		{
			v[i][j] = false;
			scanf("%d", &map[i][j]);
			if(map[i][j] == 1)
			{
				q.push({i, j});
			}
		}
		
	while(!q.empty())
	{
		int x = q.front().first, y = q.front().second;
		
		if(safe(x + 1, y))
		{
			q.push({x + 1, y});
			if(map[x + 1][y] == 0 || day[x + 1][y] > day[x][y] + 1) day[x + 1][y] = day[x][y] + 1;
			map[x + 1][y] = 1; v[x + 1][y] = true;
		}
		if(safe(x - 1, y))
		{
			q.push({x - 1, y});
			if(map[x - 1][y] == 0 || day[x - 1][y] > day[x][y] + 1) day[x - 1][y] = day[x][y] + 1;
			map[x - 1][y] = 1; v[x - 1][y] = true;
		}
		if(safe(x, y + 1)) 
		{
			q.push({x, y + 1});
			if(map[x][y + 1] == 0 || day[x][y + 1] > day[x][y] + 1) day[x][y + 1] = day[x][y] + 1;
			map[x][y + 1] = 1; v[x][y + 1] = true;
		}
		if(safe(x, y - 1)) 
		{
			q.push({x, y - 1});
			if(map[x][y - 1] == 0 || day[x][y - 1] > day[x][y] + 1) day[x][y - 1] = day[x][y] + 1;
			map[x][y - 1] = 1; v[x][y - 1] = true;
		}
		
		// printf("%d %d\n", q.front().first, q.front().second);
		
		for(int i = 0; i < N; i++)
//		{
//			for(int j = 0; j < M; j++)
//				printf("%d ", map[i][j]);
//			printf("\n");
//		}
//		printf("\n");
		v[x][y] = true;
		
		q.pop();
	}
	
	printf("%d\n", solve());
	
//	while(!q.empty())
//	{
//		printf("%d %d\n", q.front().first, q.front().second);
//		q.pop();
//	}
}