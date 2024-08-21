#include<stdio.h>
#include<stdlib.h>
struct Array
{
    int A[10];
    int size;
    int length;
};
void display (struct Array arr)
{
    int i;
    printf("\n Elements are : \n");
    for (i=0; i<arr.length; i++)
    printf("%d ", arr.A[i]);
}
int isSorted (struct Array arr)
{
    int i;
    for (i=0; i<arr.length-1; i++)
    {
        if (arr.A[i]>arr.A[i+1])
           return 0;
    }
    return 1;
}
int main()
{
    struct Array arr1= {{2,3,9,16,18,21,8,32,35},10,9};
    printf("%d", isSorted(arr1));
    display(arr1);
    return 0;
}