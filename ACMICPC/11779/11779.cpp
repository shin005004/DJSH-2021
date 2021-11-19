#include <cstdio>
#include <vector>
using namespace std;

struct Edge{
    int to;
    int cost;
    Edge(int to, int cost): to(to), cost(cost) {  }
};

vector<Edge> a[1001];
int dist[1001];
bool check[1001];
int inf = 987654321;
int from[1001], path[1001];;

int N, M;
int main(void)
{
    scanf("%d", &N);
    scanf("%d", &M);
    for(int i = 0; i < M; i++)
    {
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        a[x].push_back(Edge(y, z));
    }

    int start, end;
    scanf("%d %d", &start, &end);
    for(int i = 1; i <= N; i++)
        dist[i] = inf;
    
    dist[start] = 0;
    for(int k = 0; k < N; k++)
    {
        int min = inf + 1;
        int x = -1;
        for(int i = 1; i <= N; i++)
            if(!check[i] && min > dist[i])
            {
                min = dist[i];
                x = i;
            }

        check[x] = 1;
        for(int i = 0; i < a[x].size(); i++)
        {
            int to = a[x][i].to;
            if(dist[to] > dist[x] + a[x][i].cost)
            {
                dist[to] = dist[x] + a[x][i].cost;
                from[to] = x;
            }
        }
    }
    int cur = end, size = 0;
    path[0] = end;
    while(from[cur] != 0)
    {
        path[++size] = from[cur];
        cur = from[cur];
    }
    
    printf("%d\n", dist[end]);
    printf("%d\n", size + 1);
    for(int i = size; i >= 0; i--)
        printf("%d ", path[i]);
    printf("\n");
    return 0;
}