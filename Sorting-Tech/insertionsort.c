#include<stdio.h>
#include<stdlib.h>
void swap(int *x, int *y)
{
    int temp=x;
    *x=*y;
    *y=temp;
}
void Insertion(int A[], int n)
{
    int i,j,x;
    for(i=0; i<n; i++)
    {
        
            j=i-1;
            x=A[i];
            while(j>-1 && A[j]>x)
            {
                A[j+1]=A[j];
                j--;
            }
            A[j+1]=x;
        
    }
}
int main()
{
    int A[]={11,13,10,7,15,12};
    int n=6;
    int i;
    for(i=0; i<10; i++)
       printf("%d",A[i]);
    printf("\n");
    return 0;
}