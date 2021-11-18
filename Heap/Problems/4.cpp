#include <cstdio>

bool isHeapIter(int a[], int size)
{
    for(int i = size; i > 1; i--)
        if(a[i / 2] > a[i]) return false;
    return true;
}

int main(void)
{
    int a[10] = {0, 15, 5, 6, 8, 9, 10};
    printf("%d\n", isHeapIter(a, 6));
    return 0;
}