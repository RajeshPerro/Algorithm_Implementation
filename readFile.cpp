#include "iostream"
#include "fstream"
#include "sys/time.h"

using namespace std;

int main(int argc, char const *argv[])
{
	int *arr;
	arr = new int[20020];
	ifstream readFile;
	readFile.open("OlsenGangPin.txt");
	for (int i = 0; i < 20000; ++i)
	{
		readFile>>arr[i];
	}

	cout<<"Data get from File : "<<endl;
	for (int i = 0; i < 20000; ++i)
	{
		cout<<arr[i]<<" ";
	}
	

	return 0;
}