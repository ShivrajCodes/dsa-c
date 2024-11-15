#include<stdio.h>
#include<stdlib.h>
void swap(int *x, int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}
void Bubble(int A[], int n)
{
    int i,j,flag=0;
    for(i=0;i<n;i++)
    {
        flag=0;
        for(j=0; j<n-i-1; j++)
        {
            if(A[j]>A[j+1])
            {
                swap(&A[j],&A[j+1]);
                flag=1;
            }
        }
        if(flag==0)
           break;

    }
}
int main()
{
    int A[]={11,13,7,12,12,6};
    int n=6;
    int i;
    for(i=0; i<10; i++)
       printf("%d",A[i]);
    printf("\n");
    return 0;
}