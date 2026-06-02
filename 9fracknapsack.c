#include <stdio.h>

struct Item
{
    int weight;
    int profit;
    float ratio;
};

int main()
{
    int n, capacity;

    printf("Enter number of items: ");
    scanf("%d", &n);

    struct Item item[n];

    printf("Enter profits:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &item[i].profit);

    printf("Enter weights:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &item[i].weight);

    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);

    for (int i = 0; i < n; i++)
        item[i].ratio = (float)item[i].profit / item[i].weight;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (item[j].ratio < item[j + 1].ratio)
            {
                struct Item temp = item[j];
                item[j] = item[j + 1];
                item[j + 1] = temp;
            }
        }
    }

    float totalProfit = 0.0;

    for (int i = 0; i < n; i++)
    {
        if (capacity >= item[i].weight)
        {
            totalProfit += item[i].profit;
            capacity -= item[i].weight;
        }
        else
        {
            totalProfit += item[i].ratio * capacity;
            break;
        }
    }

    printf("Maximum Profit = %.2f\n", totalProfit);

    return 0;
}