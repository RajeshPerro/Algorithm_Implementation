#include "iostream"
#include <algorithm> 

using namespace std;

int main(int argc, char const *argv[])
{
	int* arr_1;
	int* arr_2;
	arr_1 = new int[5];
	for (int i = 5; i > 0; i--)
	 {
	 	arr_1[i] = i;
	 	
	 } 

	arr_2 = new int[4];
	for (int i = 4; i > 0; i--)
	 {
	 	arr_2[i] = i;
	 	cout<<arr_2[i]<<" ";
	 } 
	 cout<<endl;

	 int* result;
	 result = new int[12];
	 //reverse_copy(arr1,arr1+5,result);
	 //reverse_copy(arr2,arr2+4,result+6);
	 for (int i = 0; i < 5; ++i)
	 {
	 	result[i] = arr_1[i];
	 }
	 for (int k = 5; k < 9; ++k)
	 {
	 	result[k] = arr_2[k];
	 }

	 for (int j = 0; j < 12; ++j)
	 {
	 	cout<<"The result array is : "<<result[j]<<" "<<endl;
	 }

int arr1[50], arr2[50], size1, size2, size, i, j, k, merge[100];
	cout<<"Enter Array 1 Size : ";
	cin>>size1;
	cout<<"Enter Array 1 Elements : ";
	for(i=0; i<size1; i++)
	{
		cin>>arr1[i];
	}
	cout<<"Enter Array 2 Size : ";
	cin>>size2;
	cout<<"Enter Array 2 Elements : ";
	for(i=0; i<size2; i++)
	{
		cin>>arr2[i];
	}
	for(i=0; i<size1; i++)
	{
		merge[i]=arr1[i];
	}
	size=size1+size2;
	for(i=0, k=size1; k<size && i<size2; i++, k++)
	{
		merge[k]=arr2[i];
	}
	cout<<"Now the new array after merging is :\n";
	for(i=0; i<size; i++)
	{
		cout<<merge[i]<<" ";
	}
	return 0;
}