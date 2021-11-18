#include <iostream>
#include <cstdio>
using namespace std;

int a[50][2];
void preorder(int x)
{
    if(x == (-1)) return;
    
    printf("%c ", x + 65);
    preorder(a[x][0]);
    preorder(a[x][1]);
}

void inorder(int x)
{
    if(x == -1) return;
    
    inorder(a[x][0]);
    printf("%c ", x + 65);
    inorder(a[x][1]);
}

void postorder(int x)
{
    if(x == -1) return;
    
    postorder(a[x][0]);
    postorder(a[x][1]);
    printf("%c ", x + 'A');
}

int main(void)
{
    int n;
    scanf("%d", &n);

    for(int i = 1; i <= n; i++)
    {
        char x, y, z;
        fflush(stdin);
        scanf("%c %c %c", &x, &y, &z);
        x = x - 'A';
        
        if(y == '.')
            a[x][0] = -1;
        else
            a[x][0] = y - 'A';
        if(z == '.')
            a[x][1] = -1;
        else    
            a[x][1] = z - 'A';
        
        printf("%d %d %d\n", x, a[x][0], a[x][1]);
    }

    preorder(0);
    printf("\n");
    // inorder(0);
    // printf("\n");
    // postorder(0);
    // printf("\n");
}