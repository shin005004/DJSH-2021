// failed
#include <cstdio>
using namespace std;

int in[100005], post[100005];
int n;

// s_in <=   < s_out 
int divide(int s_in, int s_out, int p_in, int p_out)
{
    int size = s_out - s_in;
    if(size == 0) return 0;

    int node = post[p_out - 1];
    printf("%d ", node);

    if(size <= 1) return 0;
    
    int id;
    for(int i = s_in; i < s_out; i++)
        if(in[i] == node)
            id = i;
    
    int in_size = id - s_in, post_size = p_out - id - 1;
    divide(s_in, id, p_in, p_in + in_size);
    divide(id + 1, s_out, p_in + in_size, p_out - 1);
}

int main(void)
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &in[i]);
    for(int i = 0; i < n; i++)
        scanf("%d", &post[i]);
    
    divide(0, n, 0, n);
}