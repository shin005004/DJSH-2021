#include <cstdio>
#include <queue>
using namespace std;

int N, K;
int visited[300000];
int main(void)
{
    scanf("%d %d", &N, &K);

    queue<int> q;
    q.push(N);
    visited[N] = 1;

    while(!q.empty())
    {
        int cur = q.front();
        q.pop();

        // printf("%d ", cur);
        if(cur == K)
            break;

        if(!visited[cur + 1] && cur < (K * 4 / 3 + 5))
        {
            q.push(cur + 1);
            visited[cur + 1] = visited[cur] + 1;
        }
        if(!visited[cur - 1] && cur > 0)
        {
            q.push(cur - 1);
            visited[cur - 1] = visited[cur] + 1;
        }
        if(!visited[cur * 2] && cur * 2 < (K * 4 / 3 + 5))
        {
            q.push(cur * 2);
            visited[cur * 2] = visited[cur] + 1;
        }
    }
    printf("%d\n", visited[K] - 1);
}