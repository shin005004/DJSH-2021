#include <cstdio>
#include <algorithm>
using namespace std;

struct C{
    int to;
    int cost;
};

int main(void)
{
    C c = C{1, 2};
    printf("%d %d\n", c.to, c.cost);
    
    int x = 1;
    printf("%c \n", x + 'A');

    int a[] = {1,3, 2, 5, 4};
    sort(a, a + 5);
    for(int x: a)
        printf("%d ", x);

       
}