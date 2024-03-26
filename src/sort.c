#include "../includes/stack.h"

int bubbleSort(int *arr, int count)
{
    int i;
    int j;
    int temp;

    i = -1;
    while (++i < count)
    {
        j = i;
        while (++j < count)
        {
            if (arr[j] < arr[i])
            {
                temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }
}

int main()
{
    int a[] = {3, 233, 2, 87, 77, 123, 53, 12, 34, 53};
    bubbleSort(a, 10);
    printIntArray(a, 10);   
}