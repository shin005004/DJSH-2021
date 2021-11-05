// failed

#include <cstdio>
#include <vector>
#include <iostream>
// #include <queue>
using namespace std;

vector<pair<int, int>> node[100005];
bool check[100005];

int maxHeight = 0;
void solve(int id, int height)
{
    check[id] = true;
    // printf("%d\n", height);
    if(maxHeight < height) maxHeight = height;

    for(int i = 0; i < node[id].size(); i++)
    {
        int to = node[id][i].first;
        if(!check[to])
            solve(to, height + node[id][i].second);
    }
}

int V;
int main(void)
{
    scanf("%d", &V);
    for(int i = 0; i < V; i++)
    {
        int id;
        cin >> id;

        while(1)
        {
            int a, b;
            cin >> a;

            if(a == -1) break;
            cin >> b;

            node[id].emplace_back(a, b);
            // printf(" %d %d %d\n", id, a, b);
        }
    }

    for(int i = 1; i <= V; i++)
    {
        for(int j = 1; j <= V; j++)
            check[j] = false;
            solve(i, 0);

    }
    printf("%d\n", maxHeight);
}