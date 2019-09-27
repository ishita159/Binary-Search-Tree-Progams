#include <stdio.h>
#include <bits/stdc++.h>
int main()
{
    int test;
    scanf("%d", &test);
    while(test--)
    {
        int n, dd, i;
        long a[100000];
        scanf("%d %d", &n, &dd);
        //printf("%d",n);
        for (i = 0; i < n; i++)
        {
            scanf("%ld", &a[i]);
        }
        int count = 0, f;
        for (i = 0; i < n - 1; i++)
        {
            f = 0;
            for (int j = i + 1; j < n; j++)
            {
                if ((i != j) && (a[i] == a[j]))
                {
                    f = 1;
                    break;
                }
            }
            if (f == 0)
                count++;
        }
        count++;
        if (count > dd)
            printf("Average");
        else if (count == dd)
            printf("Good");
        else
            printf("Bad");
        printf("\n");
    }
}