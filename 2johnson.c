#include <stdio.h>

int getMobile(int a[], int dir[], int n)
{
    int mobile = 0, pos = -1;

    for (int i = 0; i < n; i++)
    {
        if (dir[i] == -1 && i != 0 && a[i] > a[i - 1] && a[i] > mobile)
        {
            mobile = a[i];
            pos = i;
        }

        if (dir[i] == 1 && i != n - 1 && a[i] > a[i + 1] && a[i] > mobile)
        {
            mobile = a[i];
            pos = i;
        }
    }

    return pos;
}

void printPermutation(int a[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int main()
{
    int n;

    printf("Enter n: ");
    scanf("%d", &n);

    int a[n], dir[n];

    for (int i = 0; i < n; i++)
    {
        a[i] = i + 1;
        dir[i] = -1;
    }

    printPermutation(a, n);

    while (1)
    {
        int pos = getMobile(a, dir, n);

        if (pos == -1)
            break;

        int mobile = a[pos];

        if (dir[pos] == -1)
        {
            int temp = a[pos];
            a[pos] = a[pos - 1];
            a[pos - 1] = temp;

            temp = dir[pos];
            dir[pos] = dir[pos - 1];
            dir[pos - 1] = temp;

            pos--;
        }
        else
        {
            int temp = a[pos];
            a[pos] = a[pos + 1];
            a[pos + 1] = temp;

            temp = dir[pos];
            dir[pos] = dir[pos + 1];
            dir[pos + 1] = temp;

            pos++;
        }

        for (int i = 0; i < n; i++)
        {
            if (a[i] > mobile)
                dir[i] = -dir[i];
        }

        printPermutation(a, n);
    }

    return 0;
}