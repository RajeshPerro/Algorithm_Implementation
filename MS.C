/*Merge Sort by
Rajesh Ghosh*/

#include<stdio.h>
#include<stdlib.h>
void merge_sort(int*,int,int);
void merge(int*,int,int,int);
int main(void)
{
int i,n;
int *a;
printf("Enter number of elements: ");
scanf("%d",&n);
a=(int*)calloc(n,sizeof(int));
for(i=0;i<n;i++)
{
  scanf(" %d",&a[i]);
}
merge_sort(a,0,n-1);
puts("\nThe Sorted array:");
for(i=0;i<n;i++)
{
  printf("\n%d",a[i]);
}

return 0;
}
void merge_sort(int* a,int l,int u)
{
  int m;
	if(l<u)
	{
	 m=(l+u)/2;
	 merge_sort(a,l,m);
	 merge_sort(a,m+1,u);
	 merge(a,l,m,u);
	}
}
void merge(int*a,int l,int m,int u)
{
  int i,j,s1=m-l+1, s2=u-m,k;
  int *la, *ra;
  la=(int*)calloc(s1,sizeof(int));
  ra=(int*)calloc(s2,sizeof(int));
  for(i=0;i<s1;i++)
  {
    la[i]=a[l+i];
  }
  for(i=0;i<s2;i++)
  {
    ra[i]=a[m+1+i];
  }
  for(i=0,j=0,k=l;k<=u && i<s1 && j<s2;k++)
  {
    if(la[i] <= ra[j])
	 {
	   a[k]=la[i];i++;
	 }
    else
    {
	 a[k]=ra[j];j++;
    }
  }
  if(i>=s1)
  {
   while(j<s2)
   {
	a[k]=ra[j];
    j++;
    k++;
   }
  }
  if(j>=s2)
  {
   while(i<s1)
   {
	a[k]=la[i];
    i++;
    k++;
   }
  }
}
