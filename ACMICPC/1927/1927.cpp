#include <cstdio>
#include <queue>
using namespace std;

priority_queue<int, vector<int>, greater<int>> q;

int main(void)
{
    int T, x;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &x);

        if(x == 0)
        {
            if(q.size() == 0)
                printf("0\n");
            else{
                printf("%d\n", q.top());
                q.pop();
            }
        }
        else{
            q.push(x);
        }
    }
}