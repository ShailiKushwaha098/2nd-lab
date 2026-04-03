#include <stdio.h>
#define MAX 100
int arr[MAX], n = 0;
void display()
{
    if (n == 0)
    {
        printf("Array Empty!\n");
        return;
    }
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void insert()
{
    int pos, val;
    if (n == MAX)
    {
        printf("Array Full!\n");
        return;
    }

    printf("Enter position (1-%d): ", n + 1);
    scanf("%d", &pos);
    printf("Enter value: ");
    scanf("%d", &val);

    if (pos < 1 || pos > n + 1)
    {
        printf("Invalid Position\n");
        return;
    }

    for (int i = n; i >= pos; i--)
        arr[i] = arr[i - 1];
    arr[pos - 1] = val;
    n++;
}

void delete()
{
    int pos;
    if (n == 0)
    {
        printf("Array Empty!\n");
        return;
    }

    printf("Enter position (1-%d): ", n);
    scanf("%d", &pos);

    if (pos < 1 || pos > n)
    {
        printf("Invalid Position\n");
        return;
    }

    for (int i = pos - 1; i < n - 1; i++)
        arr[i] = arr[i + 1];
    n--;
}

void search()
{
    int key, found = 0;
    printf("Enter element to search: ");
    scanf("%d", &key);

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            printf("Found at position %d\n", i + 1);
            found = 1;
            break;
        }
    }
    if (!found)
        printf("Not Found!\n");
}

void bubble()
{
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
    printf("Sorted Successfully\n");
}

int main()
{
    int ch;
    do
    {
        printf("\n1.Display\n2.Insert\n3.Delete\n4.Search\n5.Sort\n6.Exit\nChoice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            display();
            break;
        case 2:
            insert();
            break;
        case 3:
            delete();
            break;
        case 4:
            search();
            break;
        case 5:
            bubble();
            break;
        case 6:
            break;
        default:
            printf("Invalid Choice\n");
        }
    } while (ch != 6);
}
