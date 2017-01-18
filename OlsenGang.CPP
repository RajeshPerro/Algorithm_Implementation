#include "iostream"
#include "fstream"
#include "sys/time.h"

using namespace std;

class Sorting
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

  int* CountingSort(int* ,int,int);
  
};

void Sorting::bubbleSort(int arra[], int n )
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
  // for (int i = 0; i < n; ++i)
  // {
  //   cout<<arra[i]<<" ";
  // }
}

void Sorting::insertionSort(int arra[], int n)
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
  // for (int i = 0; i < n; ++i)
  // {
  //   cout<<arra[i]<<" ";
  // }
}

void Sorting::merge(int*a,int l,int m,int u)
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
void Sorting::mergeSort(int* a,int l,int u)
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

void Sorting::quickSort(int arra[], int p, int r )
{
  int q;
    if(p<r)
    {
       q=partition(arra,p,r);
       quickSort(arra,p,q-1);
       quickSort(arra,q+1,r);
    }
}
int Sorting::partition(int arra[],int p,int r)
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

int* Sorting::CountingSort(int *T,int m,int len)
{
  int *count_arr, *Tprime, *B;

  count_arr = (int *)calloc(m,sizeof(int));
  B = (int *)calloc(m,sizeof(int));

  Tprime = (int *)calloc(len,sizeof(int));

  for (int i = 0; i < m; ++i)
  {
    count_arr[i] = 0;
    B[i] =0;
  }

  for (int c = 0; c < len; ++c)
  {
    /* code */
    count_arr[T[c]]++; 
  }

  for (int j = 1; j < m; ++j)
  {
    B[j] = B[j-1]+count_arr[j-1];
  }
  for (int i = 0; i < len; ++i)
  {
    /* code */
    Tprime[B[T[i]]] = T[i];
    B[T[i]]++;
  }
return Tprime;

}

typedef unsigned long long timestamp_t;
  static timestamp_t
    get_timestamp ()
    {
      struct timeval now;
      gettimeofday (&now, NULL);
      return  now.tv_usec + (timestamp_t)now.tv_sec * 1000000000;
    }

int main(int argc, char const *argv[])
{
    Sorting sort;
    ofstream testFile;
    double secs;
    int k=10010;
    /*Real data reader code START*/
    ifstream ReadFile;
    int SIZE = 20000;
    string *creditCardNo;
    int *pinNo;
    int *tempPinNo;
    int flag = 0;
  
  creditCardNo = new string[SIZE];
  pinNo = new int[SIZE];
  tempPinNo = new int[SIZE];

  /* Real Data Reader CODE END*/


    /*---Reading CC Numbers and Pin Numbers From Text File START---*/
    ReadFile.open("CreditCardInfo.txt");
    for (int i = 0; i < SIZE; i++)
    {
      ReadFile>>creditCardNo[i]>>pinNo[i];
    }
    ReadFile.close();
    /*---Reading CC Numbers and Pin Numbers From Text File END---*/

    /*---Storing Pin Numbers in a tempArray START---*/
    for (int j = 0; j < SIZE; j++)
    {
      tempPinNo[j] = pinNo[j];
    }

    /*---Storing Pin Numbers in a tempArray END---*/

    testFile.open("OlsenGangSort.txt",ofstream::out | std::ofstream::app);
   
    /*-->>>>>>>BUBBLE SORT<<<<<<<----*/
    
    secs=0;
    timestamp_t t0 = get_timestamp();
    
    sort.bubbleSort(pinNo,SIZE);
    
    timestamp_t t1 = get_timestamp();
    secs+= (t1 - t0) / 1000000.0;
    testFile<<"Time for Sorting all Pin by using BubbleSort : "<<secs*1000 <<" Millisecond"<<endl;
    cout<<"After Performing BubbleSort time is : "<<secs;
    cout<<endl;

    /*-->>>>>>>INSERTION SORT<<<<<<<----*/
    secs=0;
    timestamp_t t2 = get_timestamp();
    
    sort.insertionSort(pinNo,SIZE);

    timestamp_t t3 = get_timestamp();
    secs+= (t3 - t2) / 1000000.0;
    testFile<<"Time for Sorting all Pin by using InsertionSort : "<<secs*1000 <<" Millisecond"<<endl;
    cout<<"After Performing InsertionSort time is : "<<secs;
    cout<<endl;

    /*-->>>>>>>MERGE SORT<<<<<<<----*/
    
    secs=0;
    timestamp_t t4 = get_timestamp();

    sort.mergeSort(pinNo,0, SIZE-1);
    
    timestamp_t t5 = get_timestamp();
    secs+= (t5 - t4) / 1000000.0;
    testFile<<"Time for Sorting all Pin by using MergeSort : "<<secs*1000 <<" Millisecond"<<endl;
    cout<<"After Performing MergeSort time is : "<<secs;
    cout<<endl;
   
    /*-->>>>>>>QUICK SORT<<<<<<<----*/
    secs=0;
    timestamp_t t6 = get_timestamp();
    
    sort.quickSort(pinNo, 0, SIZE-1);
    
    timestamp_t t7 = get_timestamp();
    secs+= (t7 - t6) / 1000000.0;
    testFile<<"Time for Sorting all Pin by using QuickSort : "<<secs*1000 <<" Millisecond"<<endl;
    cout<<"After Performing QuickSort time is : "<<secs;
    cout<<endl;

    /*-->>>>>>>COUNTING SORT<<<<<<<----*/
    secs=0;
    timestamp_t t8 = get_timestamp();
    
    sort.CountingSort(pinNo, k, SIZE);
    
    timestamp_t t9 = get_timestamp();
    secs+= (t9 - t8) / 1000000.0;
    testFile<<"Time for Sorting all Pin by using CountingSort : "<<secs*1000 <<" Millisecond"<<endl;
    cout<<"After Performing CountingSort time is : "<<secs;
    cout<<endl<<endl;

  testFile<<endl<<endl;  
  
  testFile<<"Credit card number  PIN"<<endl<<"------------------- ----"<<endl;
  for (int a = 0; a < SIZE; a++)
  {
    for (int b = 0; b < SIZE; b++)
    {
      if (pinNo[a] == tempPinNo[b] && (pinNo[a-1] != pinNo[a] || flag==0) )
      {
        flag = 1;
        testFile<<creditCardNo[b]<<" ";
        if (pinNo[a] <= 9)
        {
          testFile<<"000";
        }
        else if (pinNo[a] > 9 && pinNo[a] <= 99)
        {
          testFile<<"00";
        }
        else if (pinNo[a] > 99 && pinNo[a] <= 999)
        {
          testFile<<"0";
        }
        else
        {
          
        }
        testFile<<tempPinNo[b]<<endl;
      } 
    }
  }
  cout<<"*************************************************************************************************"<<endl;
  cout<<"Please Check your Program Directory you will find OlsenGangSort.txt that contains all Data."<<endl;
  cout<<"*************************************************************************************************"<<endl;
  testFile.close();
  return 0;
}