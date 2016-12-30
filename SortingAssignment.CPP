#include "iostream"

using namespace std;

class Shorting
{
  bool swaaped;
  int j,mid;
  int temp,key;
public:
  void bubbleSort(int* , int);
  
  void insertionSort(int*, int);

  void merge(int*, int, int, int );
  void mergeSort(int*, int, int);

  void quickSort(int*, int, int);
  int partition(int*, int, int);
  
};

void Shorting::bubbleSort(int arra[], int n )
{
  swaaped = true; j = 0; 
  while(swaaped)
  {
    swaaped = false;
    j++;
    for (int i = 0; i < n-j; ++i)
    {
      if (arra[i] > arra[i+1])
      {
        temp = arra[i];
        arra[i] = arra[i+1];
        arra[i+1] = temp;
        swaaped = true;  
      }
    }
  }
  for (int i = 0; i < n; ++i)
  {
    cout<<arra[i]<<" ";
  }
}

void Shorting::insertionSort(int arra[], int n)
{
  for(int k=1 ; k < n ; k++)
  {
     key=arra[k];
     int i = k-1;
     while(arra[i] > key && i >= 0)
     {
        arra[i+1] = arra[i];
        i--;
     }
     arra[i+1] = key;
  }
  for (int i = 0; i < n; ++i)
  {
    cout<<arra[i]<<" ";
  }
}

void Shorting::merge(int a[],int low,int mid,int high)
{
  
    if(high>low)
    {
      mid=(low+high)/2;
      mergeSort(a,low,mid);
      mergeSort(a,mid+1,high);
      merge(a,low,mid,high);
    }
  return;
}
void Shorting::mergeSort(int a[], int low, int high)
{
  int i, j, k;
  int b[high];
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

void Shorting::quickSort(int arra[], int p, int r )
{
  int q;
    if(p<r)
    {
       q=partition(arra,p,r);
       quickSort(arra,p,q-1);
       quickSort(arra,q+1,r);
    }
}
int Shorting::partition(int arra[],int p,int r)
{
  int x=arra[p],i;

  i=p+1;
  j=r;

  while(j>=i)
  {
    while(arra[i]<=x && i<=r)
      i++;

      while(arra[j]>x && j>=i)
        j--;
      if(j>=i)
      {
        temp = arra[i];
        arra[i] = arra[j];
        arra[j] = temp;
        i++;
        j--;
      }
  }
  temp=arra[j];
  arra[j]=arra[p];
  arra[p]=temp;
return j;
}


int main(int argc, char const *argv[])
{
  int num, arr[100];
  Shorting sort;
  cout<<"Enter the number of elements : ";
  cin >> num;
  for (int i = 0; i < num; ++i)
  {
    arr[i]=(i*num)+(num-i)*(num+i);
    //cin>>arr[i];
  }
  cout<<"Array Elements are : ";
  for (int i = 0; i < num; ++i)
  {
    cout<<arr[i]<<" ";
  }
  cout<<endl;
  
  cout<<"After Performing BubbleSort : ";
  sort.bubbleSort(arr,num);
  cout<<endl;
  
  cout<<"After Performing InsertionSort : ";
  sort.insertionSort(arr,num);
  cout<<endl;

  cout<<"After Performing MergeSort : ";
  sort.mergeSort(arr, 0, num-1);
  for (int i = 0; i < num; ++i)
  {
    cout<<arr[i]<<" ";
  }
  cout<<endl;
  
  cout<<"After Performing QuickSort : ";
  sort.quickSort(arr, 0, num-1);
  for (int i = 0; i < num; ++i)
  {
    cout<<arr[i]<<" ";
  }
  cout<<endl;
  return 0;
}