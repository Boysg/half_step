#include <stdio.h>
void bubbleSort(int *arr, int n);

int main()
{
    /*int i = 0,arr[10];
    char ch;
    do
    {
        scanf("%d",&arr[i]);
        i++;
    }
    while((ch=getchar())!='y');*/
    int arr[] = {5, 9, 3, 8, 12, 14, 1, 6}; 
    int n = sizeof(arr) / sizeof(int);
    bubbleSort(arr, n);
    getchar();
    return 0;
}

void bubbleSort(int *arr,int n)
{
    int i, j, temp, flag;
    for(i = 0; i < n - 1; i++)
    {
        flag = 0;
        for(j = 0; j < n - i - 1; j++)
        {
            if(*(arr + j) > *(arr + j + 1))
            {
                temp = *(arr + j);
                *(arr + j) = *(arr + j + 1);
                *(arr + j + 1) = temp;
                flag = 1;
            }
        }
        if(flag = 0)
        break;
    }
    for(i = 0; i < n; i++)
    {
        printf("arr[%d] = %d\n", i, *(arr + i));
    }
}