#include <cstdio>
#include <algorithm>
using namespace std;

int heap[100001], size;

int pop(void)
{
    int root = heap[1];
    heap[1] = heap[size];
    heap[size--] = 0;
    for(int i = 1; i * 2 <= size; )
    {
        if(heap[i] > heap[i * 2] && heap[i] > heap[i * 2 + 1]){
            break;
        }
        int to = i * 2;
        if(heap[i * 2] < heap[i * 2 + 1])
            to = to + 1;
        swap(heap[i], heap[to]);
        i = to;
    }
    return root;
}

void push(int x)
{
    heap[++size] = x;
    for(int i = size; i > 1; i /= 2)
    {
        int parent = i / 2;
        if(heap[parent] < heap[i])
            swap(heap[parent], heap[i]);
        else
            break;
    }
}

int main(void)
{
    int T;
    scanf("%d", &T);

    while(T--)
    {
        int x = 0;
        scanf("%d", &x);
        if(x == 0)
        {
            if(size == 0)
                printf("0\n");
            else
                printf("%d\n", pop());
        }
        else
            push(x);
    }
    return 0;
}