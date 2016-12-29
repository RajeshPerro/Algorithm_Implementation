#include "iostream"

using namespace std;

class buble
{
  bool swaaped;
  int j;
  int temp;
public:
  void bubbleSort(int* , int);
  
};
void buble::bubbleSort(int arra[], int n )
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

int main(int argc, char const *argv[])
{
  int num, arr[100];
  buble bsort;
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
  cout<<"After operatating BubbleSort : ";
  bsort.bubbleSort(arr,num);
  cout<<endl;
  return 0;
}