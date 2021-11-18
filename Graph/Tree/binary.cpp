#include <cstdio>
int n, T[1 << 10];

int main(void)
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%d", &T[i]);
    
    // int p = 0;
    // for(int t = n; t > 0; t /= 2) p++;

    // for(int i = 0; i < p; i++)
    // {
    //     int temp = 1<<(i);
    //     // for(int t = 0; t < i; t++) temp *= 2; 
    //     for(int j = 0; j < temp; j++)
    //     {
    //         printf("%d ", T[j]);
    //     }
    //     printf("\n");
    // }

    int num1 = 1, num2 = 1;
    for(int i = 1; i <= n; i++)
    {
        printf("%d ", T[i]);
        if(i == num1)
        {
            num2 *= 2;
            num1 += num2;
            
            printf("\n");
        }
    }
}