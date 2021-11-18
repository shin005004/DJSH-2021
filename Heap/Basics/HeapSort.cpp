
#include <cstdio>
#include <cstdlib>

class HeapNode{
public:
    int key;
    HeapNode(int k = 0) :key(k){ }
    void setKey(int k) { key = k; };
};

class MaxHeap{
public:
    HeapNode node[200];
    int size;

    MaxHeap():size(0) {};
    bool isEmpty() { return size == 0; }
    bool isFull() { return size = 200 - 1; }

    HeapNode& getParent(int i) { return node[i / 2]; }
    HeapNode& getLeft(int i) { return node[i * 2]; }
    HeapNode& getRight(int i) { return node[i * 2 + 1]; }

    void insert(int key)
    {
        int i = ++size;

        while(i != 1 && key > getParent(i).key)
        {
            node[i] = getParent(i);
            i /= 2;
        }
        node[i].key = key;
    }
    HeapNode remove()
    {
        HeapNode item = node[1];
        HeapNode last = node[size--];

        int parent = 1;
        int child = 2;
        while(child <= size)
        {
            if(child < size && getLeft(parent).key < getRight(parent).key)
                child++;
            
            if(last.key >= node[child].key) break;

            node[parent] = node[child];
            parent = child;
            child *= 2;
        }
        node[parent] = last;
        return item;
    }
    HeapNode find() { return node[1]; }

    void display()
    {
        for(int i = 1, level = 1; i <= size; i++)
        {
            if(i == level)
            {
                printf("\n");
                level *= 2;
            }
            printf("%4d", node[i].key);
        }
        printf("\n---------------------------------");
    }
};

void HeapSort(int a[], int n) 
{
    MaxHeap h;

    for(int i = 0; i < n; i++)
        h.insert(a[i]);
    for(int i = n - 1; i >= 0; i--)
        a[i] = h.remove().key;
}

int main(void)
{
    MaxHeap heap;

    int data[100];
    for(int i = 0; i < 10; i++)
        data[i] = rand() % 100;

    printf("\nBefore: ");
    for(int i = 0; i < 10; i++)
        printf(" %3d", data[i]);
    HeapSort(data, 10);
    printf("\nAfter: ");
    for(int i = 0; i < 10; i++)
        printf(" %3d", data[i]);
    printf("\n");

    return 0;
}