#include "iostream"
#include "fstream"
#include "sys/time.h"

using namespace std;

class Shorting
{
  bool swaaped;
  int j,mid;
  int temp,key;
public:
  void bubbleSort(int* , int);
  
  void insertionSort(int*, int);

  void mergeSort(int*,int,int);
  void merge(int*,int,int,int);

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
      //cout<<"Inside: "<<i<<endl;
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

void Shorting::merge(int*a,int l,int m,int u)
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
void Shorting::mergeSort(int* a,int l,int u)
{
  int m;
  if(l<u)
  {
   m=(l+u)/2;
   mergeSort(a,l,m);
   mergeSort(a,m+1,u);
   merge(a,l,m,u);
  }
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

typedef unsigned long long timestamp_t;
  static timestamp_t
    get_timestamp ()
    {
      struct timeval now;
      gettimeofday (&now, NULL);
      return  now.tv_usec + (timestamp_t)now.tv_sec * 1000000000;
    }
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

int main(int argc, char const *argv[])
{
    ofstream testFile;
    double secs;
    int num;
    int *arrBub,*arrIns,*arrMer,*arrQui;
    Shorting sort;
    cout<<"Enter the number of elements you wnat to sort (numbers will be generated randomly): ";
    cin >> num;

    testFile.open("SortingFile.txt",ofstream::out | std::ofstream::app);
    
    cout<<"Unsorted List : ";
    arrBub = genRandomArray(num);

    for (int i = 0; i < num; ++i)
    {
      cout<<arrBub[i]<<" ";
    }
    cout<<endl;

    /*-->>>>>>>BUBBLE SORT<<<<<<<----*/
    cout<<"After Performing BubbleSort : ";
    secs=0;
    timestamp_t t0 = get_timestamp();
    
    sort.bubbleSort(arrBub,num);
    
    timestamp_t t1 = get_timestamp();
    secs+= (t1 - t0) / 1000000.0;
    testFile<<"Time for Sorting "<<num <<" elements in BubbleSort : "<<secs*1000 <<" Millisecond"<<endl;
    cout<<endl;
    /*-->>>>>>>INSERTION SORT<<<<<<<----*/
    cout<<endl<<"Unsorted List : ";
    arrIns = genRandomArray(num);
    for (int i = 0; i < num; ++i)
    {
      cout<<arrIns[i]<<" ";
    }
    cout<<endl;
    cout<<"After Performing InsertionSort : ";
    secs=0;
    timestamp_t t2 = get_timestamp();
    
    sort.insertionSort(arrIns,num);

    timestamp_t t3 = get_timestamp();
    secs+= (t3 - t2) / 1000000.0;
    testFile<<"Time for Sorting "<<num <<" elements in InsertionSort : "<<secs*1000 <<" Millisecond"<<endl;
    cout<<endl;
    /*-->>>>>>>MERGE SORT<<<<<<<----*/
    cout<<endl<<"Unsorted List : ";
    arrMer = genRandomArray(num);
    for (int i = 0; i < num; ++i)
    {
      cout<<arrMer[i]<<" ";
    }
    cout<<endl;
    cout<<"After Performing MergeSort : ";
    secs=0;
    timestamp_t t4 = get_timestamp();

    sort.mergeSort(arrMer, 0, num-1);
    
    timestamp_t t5 = get_timestamp();
    secs+= (t5 - t4) / 1000000.0;
    testFile<<"Time for Sorting "<<num <<" elements in MergeSort : "<<secs*1000 <<" Millisecond"<<endl;
    
    for (int i = 0; i < num; ++i)
    {
      cout<<arrMer[i]<<" ";
    }
    cout<<endl<<endl;
    /*-->>>>>>>QUICK SORT<<<<<<<----*/
    cout<<endl<<"Unsorted List : ";
    arrQui = genRandomArray(num);
    for (int i = 0; i < num; ++i)
    {
      cout<<arrQui[i]<<" ";
    }
    cout<<endl;

    cout<<"After Performing QuickSort : ";
    secs=0;
    timestamp_t t6 = get_timestamp();
    
    sort.quickSort(arrQui, 0, num-1);
    
    timestamp_t t7 = get_timestamp();
    secs+= (t7 - t6) / 1000000.0;
    testFile<<"Time for Sorting "<<num <<" elements in QuickSort : "<<secs*1000 <<" Millisecond"<<endl;
    for (int i = 0; i < num; ++i)
    {
      cout<<arrQui[i]<<" ";
    }
    cout<<endl<<endl;
    cout<<"*************************************************************************************************"<<endl;
    cout<<"Please Check your Program Directory you will find SortingFile.txt that contains all operation time."<<endl;
    cout<<"*************************************************************************************************"<<endl;;
  testFile.close();
  return 0;
}