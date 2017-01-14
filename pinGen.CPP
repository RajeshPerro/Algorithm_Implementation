#include "iostream"
#include "fstream"
#include "sys/time.h"

using namespace std;

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
	int *arr;
	ofstream testFile;
	testFile.open("OlsenGangPin.txt",ofstream::out | std::ofstream::app);
	arr = genRandomArray(20000);
	for (int i = 0; i < 20000; ++i)
	{
		testFile<<arr[i]<<endl;
	}
	cout<<"Cehck your program folder for the OlsenGangPin file"<<endl;

	return 0;
}