#include <stdio.h>
#include <vector>
using namespace std;

int a[10][10];
int main(void)
{
    int v, e;
    scanf("%d %d", &v, &e);
    for(int i = 0; i < e; i++)
    {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        a[u][v] = a[v][u] = w;
    }

    for(int i = 1; i <= v; i++)
    {
        for(int j = 1; j <= v; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
}