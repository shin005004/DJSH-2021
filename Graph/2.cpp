#include <stdio.h>
#include <vector>
using namespace std;

vector<pair<int, int>> a[10];

struct pp{
    int a;
    int b;
};

vector<pp> b[10];
int main(void)
{
    int v, e;
    scanf("%d %d", &v, &e);
    for(int i = 0; i < e; i++)
    {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        a[u].push_back({v, w});
        a[v].emplace_back(u, w);
    }

    for(int i = 1; i <= v; i++)
    {
        printf("%d: ", i);
        for(int j = 0; j < a[i].size(); j++)
            printf("(%d %d) ", a[i][j].first, a[i][j].second);
        printf("\n");
    }
}