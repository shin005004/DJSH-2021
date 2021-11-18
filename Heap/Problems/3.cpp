#include <cstdio>

bool isHeapRecur(int a[], int i, int size)
{
    if(i > (size - 1) / 2)
        return true;
    if((!(a[i] < a[i * 2]) && i * 2 <= size) || (!(a[i] < a[i * 2 + 1]) && i * 2 + 1 <= size))
        return false;

    if((!isHeapRecur(a, i * 2, size) && i * 2 <= size) || (!isHeapRecur(a, i * 2 + 1, size) && i * 2 + 1 <= size))
        return false;
    return true;
}

int main(void)
{
    int a[10] = {0, 15, 5, 6, 8, 9, 10};
    printf("%d\n", isHeapRecur(a, 1, 6));
    return 0;
}