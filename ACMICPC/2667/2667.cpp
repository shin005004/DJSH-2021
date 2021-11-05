#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int N, co = 0;
int map[26][26];
int visited[26][26];
int altX[4] = {0, 0, 1, -1};
int altY[4] = {1, -1, 0, 0};
int sizes[1000];

void dfs(int x, int y, int id)
{
    visited[x][y] = id;
    sizes[co] += 1;
    for(int i = 0; i < 4; i++)
    {
        int newX = x + altX[i], newY = y + altY[i];
        if(newX < N && newX >= 0 && newY < N && newY >= 0 && map[newX][newY] && !visited[newX][newY])
            dfs(newX, newY, id);
    }
}

int main(void)
{
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            char temp;
            scanf("%c", &temp);
            getchar();

            if(temp == '0')
                map[i][j] = 0;
            else
               map[i][j] = 1;
        }
    }
    
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            if(!visited[i][j] && map[i][j])
                dfs(i, j, ++co);


    sort(sizes + 1, sizes + co);

    for(int i = 1; i <= co; i++)
        printf("%d\n", sizes[i]);
}