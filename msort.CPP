#include <stdio.h>

#include "iostream"

using namespace std;

void merge(int a[],int low,int mid,int high);
void mergesort(int a[], int low, int high);

int* genRandomArray(int size)
{
  int *array;
  int SIZE = size+10;
  array = new int[SIZE];
  srand(time(NULL));
  for(int i=0;i<size;i++)
    {
      array[i]=(rand()%1000); //Generating random number and storing in array
    }
return array;   
}    

int main()
{
	int p,a;
	int *arr;
	cout<<"Enter the number : ";
	cin>>a;

	// printf("\n\tEnter The Values into ARRAY 5");
	// for( p=0;p<5;p++)
	// {
		
	// 	scanf("%d",&a[p]);
	// }
	arr = genRandomArray(a);
	mergesort(arr, 0, a-1);
	printf("\nThe Sorting List is: \n");
	for(p=0;p<a;p++)
	{
        printf("%d ",arr[p]);
	}
	
	return 0;
}


void mergesort(int a[], int low, int high)
{
    int mid;
    if(high>low)
	{
		mid=(low+high)/2;
		mergesort(a,low,mid);
		mergesort(a,mid+1,high);
		merge(a,low,mid,high);
	}
	return;
}

void merge(int a[], int low, int mid, int high)
{
    int i, j, k;
	int b[5];
    i=low;
    j=mid+1;
    k=low;
    while((i<=mid)&&(j<=high))
	{
        if(a[i]<a[j])
		{
            b[k]=a[i];
            k++;
            i++;
		}
        else
		{
            b[k]=a[j];
            k++;
            j++;
		}
	}
    while(i<=mid)
	{
        b[k]=a[i];
        k++;
        i++;
	}
    while(j<=high)
	{
        b[k]=a[j];
        k++;
        j++;
	}
    for(i=low;i<k;i++)
	{
        a[i]=b[i];
	}
	return;
}

