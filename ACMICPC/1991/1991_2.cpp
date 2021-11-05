#include <stdio.h>
#include <iostream>
using namespace std;

int N;
int tree[100][2];

void preOrder(int id){
    if(id == -1) return;

    cout << (char)(id + 'A');
    preOrder(tree[id][0]);
    preOrder(tree[id][1]);
}
void inOrder(int id){
    if(id == -1) return;

    inOrder(tree[id][0]);
    cout << (char)(id + 'A');
    inOrder(tree[id][1]);
}
void postOrder(int id){
    if(id == -1) return;

    postOrder(tree[id][0]);
    postOrder(tree[id][1]);
    cout << (char)(id + 'A');
}

int main(void)
{
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        char x, y, z;
        cin >> x >> y >> z;
        // printf("%c %c %c\n", x, y, z);

        int id = x - 'A';
        if(y == '.') tree[id][0] = -1;
        else tree[id][0] = y - 'A';
        if(z == '.') tree[id][1] = -1;
        else tree[id][1] = z - 'A';
        // printf("%d %d %d\n", id, tree[id][0], tree[id][1]);
    }
    preOrder(0);
    cout << '\n';
    inOrder(0);
    cout << '\n';
    postOrder(0);
    cout << '\n';
    return 0;
}