// failed

#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

vector<pair<int, int>> student[10001];
int indegree[10001];
int maxTime[10001];
int cost[10001];

int main(void)
{
    int N;
    scanf("%d", &N);
    for(int i = 1; i <= N; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        for(int j = 0; j < b; j++)
        {
            int temp;
            scanf("%d", &temp);
            student[i].push_back(make_pair(temp, i));
            indegree[i]++;
        }
        cost[i] = a;
    }

    queue<pair<int, int>> q;
    for(int i = 1; i <= N; i++)
        if(indegree[i] == 0)
            q.push({i, 0});
    
    while(!q.empty())
    {
        pair<int, int> now = q.front();
        q.pop();
        printf("%d ", now.first);

        for(int i = 0; i < student[now.first].size(); i++)
        {
            int to = student[now.first][i].second;
            indegree[to]--;
            
            maxTime[to] = maxTime[to] > cost[to] ? maxTime[to] : now.second + cost[to];
            if(indegree[to] == 0)
                q.push({to, maxTime[to]});
        }
        
    }
    printf("\n");

    int max = 0;
    for(int i = 1; i <= N; i++)
        if(maxTime[i] > max) max = maxTime[i];
    printf("%d\n", max);
    return 0;
}