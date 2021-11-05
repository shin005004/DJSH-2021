// copied
#include <cstdio>
using namespace std;

int in[100005], post[100005];
int idx[100005];
int n;

// s_in <=   < s_out 
void divide(int s_in, int s_out, int p_in, int p_out)
{
    if(s_in >= s_out || p_in >= p_out)
        return;
    int node = post[p_out - 1];
    printf("%d ", node);
    
    int id = idx[node];
    
    int in_size = id - s_in, post_size = p_out - id - 1;
    divide(s_in, id, p_in, p_in + id - s_in);
    divide(id + 1, s_out, p_in + id - s_in, p_out - 1);
}

int main(void)
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &in[i]);
    for(int i = 0; i < n; i++)
        scanf("%d", &post[i]);
    
    for(int i = 0; i < n; i++)
        idx[in[i]] = i;
    divide(0, n, 0, n);
    printf("\n");
}