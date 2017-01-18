#include <iostream>
#include <string>
using namespace std;

int main()
{
	const int SIZE = 8;
	string test = "10101010";
	int buffer[SIZE];

	for(int i = 0; i < SIZE; i++){
		buffer[i] = test[i]-48;
	}

	for(int i = 0; i < SIZE; i++){
		cout << buffer[i];
	}

	cout<<endl;
	return 0;
}