#include <stdio.h>
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[], int n, int i)
{
    int small = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] < arr[small])
        small = left;

    if (right < n && arr[right] < arr[small])
        small = right;

    if (small != i)
    {
        swap(&arr[i], &arr[small]);
        heapify(arr, n, small);
    }
}
void heapSort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    for (int i = n - 1; i >= 0; i--)
    {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}
void delete (int arr[], int n)
{
    swap(&arr[n - 1], &arr[0]);
    arr[n - 1] = '\0';
    heapSort(arr, n);
}
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        if (arr[i] == '\0')
        {
            continue;
        }
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main()
{
    int n;
    printf("Enter no of elements\n");
    scanf("%d", &n);
    int arr[n], option;
    printf("Enter Elemnts\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    heapSort(arr, n);
    while (1)
    {
        printf("Enter option\n1.Delete\n2.Display\n");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            delete (arr, n);
            break;
        case 2:
            printArray(arr, n);
            break;
        default:
            printf("Invalid Input\n");
            break;
        }
    }
}