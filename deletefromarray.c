#include<stdio.h>
  struct Array
    {
        int A[10];
        int size;
        int length;
    };
void display(struct Array arr)
{
    int i;
    printf("Elements in the array are: \n");
    for(i=0;i<arr.length; i++)
    printf("%d ",arr.A[i]);
}
void delete (struct Array *arr, int index)
{
    int x=0;
    int i;
    if (index>=0 && index<arr->length)
    {
        //x=arr->A[index];
        for(i=index; i<arr->length-1;i++)
        arr->A[i]=arr->A[i+1];
        arr->length --;
        

    }
    
}
int main()
{
    struct Array arr={{2,3,4,5,6},10,5};
    display(arr);
    delete(&arr,4);
    printf("Array after deletion \n");
    display(arr);

}

  
