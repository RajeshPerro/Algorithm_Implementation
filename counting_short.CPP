#include "iostream"
using namespace std;

int * CountingShort(int *T,int m,int len)
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
int* genRandomArray(int size)
{
  int *array;
  int SIZE = size+10;
  array = new int[SIZE];
  srand(time(NULL));
  for(int i=0;i<size;i++)
    {
      array[i]=(rand()%9000 + 1000); 
    }
return array;   
}    

int main(int argc, char const *argv[])
{
	int *arr, *sortarr,n,k;
	cout <<"Array Size : ";
	cin >> n;
	arr = genRandomArray(n);
	cout<<"Unsorted List : ";
	for (int i = 0; i < n; ++i)
	{
		cout<<arr[i]<<" ";
	}
	cout <<"Enter the K : ";
	cin >>k;

	sortarr = CountingShort(arr,k,n);
	cout <<"Sorting array : ";

	for (int i = 0; i < n; ++i)
	{
		/* code */
		cout<<sortarr[i]<<" ";
	}
	cout <<endl;
	

	return 0;
}