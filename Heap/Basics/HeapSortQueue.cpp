#include <cstdio>
#include <cstdlib>
#include <queue>
using namespace std;

void HeapSortDec(int a[], int n)
{
    priority_queue<int> maxHeap;
    for(int i = 0; i < n; i++)
        maxHeap.push(a[i]);
    for(int i = 0; i < n; i++)
    {
        a[i] = maxHeap.top();
        maxHeap.pop();
    }
}

void HeapSortInc(int a[], int n)
{
    // priority_queue<int> maxHeap;
    // for(int i = 0; i < n; i++)
    //     maxHeap.push(a[i]);
    // for(int i = n - 1; i >= 0; i--)
    // {
    //     a[i] = maxHeap.top();
    //     maxHeap.pop();
    // }

    priority_queue<int, vector<int>, greater<int>> minHeap;
    for(int i = 0; i < n; i++)
        minHeap.push(a[i]);
    for(int i = 0; i < n; i++)
    {
        a[i] = minHeap.top();
        minHeap.pop();
    }
}

int main(void)
{
    int data[100];
    for(int i = 0; i < 10; i++)
        data[i] = rand() % 100;

    printf("\nBefore: ");
    for(int i = 0; i < 10; i++)
        printf(" %3d", data[i]);
    HeapSortInc(data, 10);
    printf("\nAfter: ");
    for(int i = 0; i < 10; i++)
        printf(" %3d", data[i]);
    printf("\n");

    return 0;
}