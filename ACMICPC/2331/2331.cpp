#include <cstdio>

int visited[1000000];
int A, P;

int next(int a, int p)
{
    int count = 0;
    for(int temp = a; temp > 0; temp /= 10)
    {
        int num = 1;
        for(int i = 0; i < p; i++)
            num *= (temp % 10);
        count += num;
    }
            
    return count;
}

int main(void)
{
    scanf("%d %d", &A, &P);
    for(int i = 0; i < 1000000; i++)
        visited[i] = 0;
    visited[A] = 1;
    while(1)
    {
        // printf("%d %d\n", A, visited[A]);
        int newA = next(A, P);
        if(visited[newA])
        {
            printf("%d\n", visited[newA] - 1);
            return 0;
        }
        visited[newA] = visited[A] + 1;
        A = newA;
    }
}