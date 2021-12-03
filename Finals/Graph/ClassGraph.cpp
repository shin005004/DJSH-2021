#include <cstdio>
#define MAX_VTXS 256

class AdjMatGraph{
protected:
    int size;
    char verticies;
    int adj[MAX_VTXS][MAX_VTXS];
public:
    AdjMatGraph() {};
    char getVertex(int i) { return verticies[i]; }
    int getEdge(int i, int j) { return adf[i][j] ;}
    void setEdge(int i, int j, int val) { adf[i][j] = val; }

    bool isEmpty() { return size == 0; }
    bool isFull() { return size >= MAX_VTXS; }

    void reset()
    {
        size = 0;
        for(int i = 0; i < MAX_VTXS; i++)
            for(int j = 0; j < MAX_VTXS; j++)
                setEdge(i, j, 0);
    }

    void insertVertex(char name)
    {
        if(!isFull())
            verticies[size++] = name;
            else printf("Error");
    }

    void insertEdge(int u, int v){
        setEdge(u, v, 1);
        setEdge(v, u, 1);
    }

    void display()
    {
        printf("%d\n", size);
        for(int i = 0; i < size; i++)
        {
            printf("%c", getVertex(i));
            for(int j = 0; j < size; j++)
                printf(" %3d", getEdge(i, j));
            printf("\n");
        }
    }
};

