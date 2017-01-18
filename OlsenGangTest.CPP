#include "iostream"
#include "fstream"
#include "string"
#include "sys/time.h"

using namespace std;
void bubbleSort(int arra[], int n )
{
	
  bool swaaped = true; int j = 0,temp; 
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
int main(int argc, char const *argv[])
{
	ifstream ReadFile;
	ofstream WriteFile;
	int SIZE = 20000;
	string *creditCardNo;
	int *pinNo;
	int *tempPinNo;
	int flag = 0;
	
	creditCardNo = new string[SIZE];
	pinNo = new int[SIZE];
	tempPinNo = new int[SIZE];

	ReadFile.open("CreditCardInfo.txt");
	for (int i = 0; i < SIZE; i++)
	{
		ReadFile>>creditCardNo[i]>>pinNo[i];
	}
	for (int j = 0; j < SIZE; j++)
	{
		tempPinNo[j] = pinNo[j];
	}

	for (int i = 0; i < 5; ++i)
	{
		cout<<creditCardNo[i]<<" "<<pinNo[i]<<"\t"<<tempPinNo[i]<<endl;
	}
	bubbleSort(pinNo,SIZE);
	for (int i = 0; i < 10; ++i)
	{
		cout<<pinNo[i]<<endl;
	}
	for (int a = 0; a < 50; a++)
	{
		for (int b = 0; b < SIZE; b++)
		{
			if (pinNo[a] == tempPinNo[b] && (pinNo[a-1] != pinNo[a] || flag==0) )
			{
				flag = 1;
				cout<<creditCardNo[b]<<" ";
				if (pinNo[a] <= 9)
				{
					cout<<"000";
				}
				else if (pinNo[a] > 9 && pinNo[a] <= 99)
				{
					cout<<"00";
				}
				else if (pinNo[a] > 99 && pinNo[a] <= 999)
				{
					cout<<"0";
				}
				else
				{
					continue;
				}
				cout<<tempPinNo[b]<<endl;
			}	
		}
	}
	cout<<endl<<endl;
	return 0;
}