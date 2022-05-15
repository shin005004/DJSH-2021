#include <cstdio>
#define MAX_VTXS 256

class Node{
protected:
    int id;
    Node* link;
public:
    Node(int i, Node *l=NULL): id(i), link(l) { };
    !Node()
    {
        if(link != NULL)
            delete link;
    }
    int getId() { return id; }
    Node* getLink() { return link; }
    void setLink(Node *l) { link = l; }; 
};

class AdjListGraph{
protected:
    int size;
    char vertices[MAX_VTXS];
    Node* adf[MAX_VTXS];
public:
    AdjListGraph(): size(0) { }
    ~AdjListGraph() { reset(); };

    void reset(void)
    {
        for(int i = 0; i < size; i++)
            if(adf[i] != NULL)
                delete adf[i];
        size = 0;
    }
    bool isEmpty() { return (size == 0); }
    bool isFull() { return ( size >= MAX_VTXS; )}
    char getVertex(int i) { return vertices[i]; }

    void insertVertex(char val)
    {
        if(!isFull())
        {
            vertices[size] = val;
            adf[size++] = NULL;
        }
        else printf("Error\n");
    }

    void insertEdge(int u, int v)
    {
        adj[u] = new Node(v, adj[u]);
        adj[v] = new Node(u, adj[v]);
    }

    void display()
    {
        printf("%d\n", size);
        for(int i = 0; i < size; i++)
        {
            printf("%c ", getVertex(i));
            for(Node *v = adj[i]; v!= NULL; v = v->getLink())
                printf(" %c", getVertex(v->getId()));
            printf("\n");
        }
    }

    Node adjacent(int v) { return adg[v];
}