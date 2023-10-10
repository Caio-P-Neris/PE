#include <stdio.h>

int main()
{
    int entrada, n1, n2, res;
    scanf("%d", &entrada);
    while (entrada != 5)
    {
        scanf("%d", &n1);
        scanf("%d", &n2);
        if (entrada == 1)
        {
            res = n1 + n2;
        }
        else if (entrada == 2)
        {
            res = n1 - n2;
        }
        else if (entrada == 3)
        {
            res = n1 * n2;
        }
        else if (entrada == 4)
        {
            res = n1 / n2;
        }
        printf("%d\n", res);
    }
    return 0;
}
