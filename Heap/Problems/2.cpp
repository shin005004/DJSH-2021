#include <cstdio>

class MinPriorityQueue{
public:
    MinPriorityQueue(): size(0) { };
    int elem[200];
    int size;

    void insert(int data)
    {
        int i = ++size;
        while(i != 1 && data < elem[i / 2])
        {
            elem[i] = elem[i / 2];
            i /= 2;
        }
        elem[i] = data;
    }
    int remove()
    {
        int data = elem[1];
        int cur = elem[size--];

        int parent = 1;
        int child = 2;
        while(child <= size)
        {
            if(child < size && elem[parent * 2] > elem[parent * 2 + 1])
                child++;
            if(elem[parent] <= elem[child]) break;
            parent = child;
            child = parent * 2;
        }
        elem[parent] = cur;
        return data;
    }
    void display()
    {
        for(int i = 1, level = 1; i <= size; i++)
        {
            if(i == level)
            {
                printf("\n");
                level *= 2;
            }
            printf("%4d", elem[i]);
        }
        printf("\n------------------");
    }
};

int main(void)
{
    MinPriorityQueue heap;
    heap.insert(1);
    heap.insert(5);

    heap.insert(6);
    heap.insert(2);

    heap.display();
    heap.remove();
    heap.display();
}