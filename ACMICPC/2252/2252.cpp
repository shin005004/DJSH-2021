#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

vector<int> student[32001];
int indegree[32001];

int main(void)
{
    int N, M;
    scanf("%d %d", &N, &M);
    for(int i = 0; i < M; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        student[a].push_back(b);
        indegree[b]++;
    }

    queue<int> q;
    for(int i = 1; i <= N; i++)
        if(indegree[i] == 0)
            q.push(i);
    
    while(!q.empty())
    {
        int now = q.front();
        q.pop();
        printf("%d ", now);

        for(int i = 0; i < student[now].size(); i++)
        {
            indegree[student[now][i]]--;
            if(indegree[student[now][i]] == 0)
                q.push(student[now][i]);
        }
        
    }
    printf("\n");
    return 0;
}