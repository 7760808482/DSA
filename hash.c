#include <stdio.h>
#include <stdlib.h>

int key[20], n, m;
int *ht, pos;
int count = 0;

void insert(int k)
{
    pos = k % m;

    while (ht[pos] != -1)
    {
        pos = (pos + 1) % m;
    }

    ht[pos] = k;
    count++;
}

void display()
{
    int i;

    if (count == 0)
    {
        printf("\nHash Table is empty");
        return;
    }

    printf("\nHash Table contents are:\n");
    for (i = 0; i < m; i++)
        printf("T[%d] --> %d\n", i, ht[i]);
}

int main()
{
    int i;

    printf("\nEnter the number of employee records (N): ");
    scanf("%d", &n);

    printf("\nEnter the memory locations (m): ");
    scanf("%d", &m);

    ht = (int *)malloc(m * sizeof(int));

    for (i = 0; i < m; i++)
        ht[i] = -1;

    printf("\nEnter the key values:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &key[i]);

    for (i = 0; i < n; i++)
    {
        if (count == m)
        {
            printf("\nHash table is full");
            break;
        }
        insert(key[i]);
    }

    display();
    return 0;
}
