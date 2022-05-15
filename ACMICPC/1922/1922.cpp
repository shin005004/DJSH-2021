#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

bool visited[100000];
// 연결된 정점 번호, 간선 가중치 쌍
vector<pair<int, int>> mArr[100000];

int prim()
{
    visited[1] = true;

    // 가격, 현재 위치
    priority_queue<pair<int, int>> pq;

    for(auto p: mArr[1])
        pq.push(make_pair(-p.second, p.first));
        // 최대 힙으로 넣으려고
    
    int min = 0;
    while(!pq.empty())
    {
        pair<int, int> edge = pq.top();
        pq.pop();
        int to = edge.second;
        
        if(!visited[to])
        {
            visited[to] = true;
            min -= edge.first;

            for(auto p:mArr[to])
            {
                if(!visited[p.first])
                    pq.push({-p.second, p.first});
            }
        }
            
    }
    return min;
}

int N, M;

int main(void)
{
    scanf("%d", &N);
    scanf("%d", &M);

    for(int i = 0; i < M; i++)
    {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        mArr[a].push_back({b, c});
        mArr[b].push_back({a, c});
    }

    printf("%d\n", prim());
}