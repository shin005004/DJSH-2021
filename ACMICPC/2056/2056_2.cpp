#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

// 어디로
vector<int> edge[10001];
// 출입 하는 간선 개수
int indegree[10001];
// 작업에 드는 시간
int work[10001];
int visited[10001];

int main(void)
{
    int N;
    scanf("%d", &N);
    for(int i = 1; i <= N; i++)
    {
        int a, b;
        // time, how many 
        scanf("%d %d", &a, &b);
        for(int j = 0; j < b; j++)
        {
            int temp;
            scanf("%d", &temp);
            edge[temp].push_back(i);
            indegree[i]++;
        }
        work[i] = a;
    }

    // to where
    queue<int> q;
    for(int i = 1; i <= N; i++)
        if(indegree[i] == 0)
            q.push(i);
    
    while(!q.empty())
    {
        int now = q.front();
        q.pop();
        // printf("%d ", now);

        for(int i = 0; i < edge[now].size(); i++)
        {
            int to = edge[now][i];
            indegree[to]--;
            
            visited[to] = visited[to] > work[now] + visited[now] ? visited[to] : work[now] + visited[now];
            if(indegree[to] == 0)
                q.push(to);
        }
    }
    // printf("\n");

    int max = 0;
    for(int i = 1; i <= N; i++)
        if(visited[i] + work[i] > max) max = visited[i] + work[i];
    printf("%d\n", max);
    return 0;
}