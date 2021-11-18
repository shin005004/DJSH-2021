#include <cstdio>

class HeapNode{
public:
    int key;
    HeapNode(int k = 0) :key(k){ }
    void setKey(int k) { key = k; };
};

class MinHeap{
public:
    HeapNode node[200];
    int size;

    MinHeap():size(0) {};
    bool isEmpty() { return size == 0; }
    bool isFull() { return size = 200 - 1; }

    HeapNode& getParent(int i) { return node[i / 2]; }
    HeapNode& getLeft(int i) { return node[i * 2]; }
    HeapNode& getRight(int i) { return node[i * 2 + 1]; }

    void insert(int key)
    {
        int i = ++size;

        while(i != 1 && key < getParent(i).key)
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
            if(child < size && getLeft(parent).key > getRight(parent).key)
                child++;
            
            if(last.key <= node[child].key) break;

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

void MakeTree(int freq[], int n)
{
    MinHeap heap;
    for(int i = 0; i < n; i++)
        heap.insert(freq[i]);
    
    for(int i = 1; i < n; i++){
        HeapNode e1 = heap.remove();
        HeapNode e2 = heap.remove();

        heap.insert(e1.key + e2.key);
        printf("(%d+%d)\n", e1.key, e2.key);
    }
}

int main(void)
{
    int freq[] = {15, 12, 8, 6, 4};
    MakeTree(freq, 5);
    return 0;
}