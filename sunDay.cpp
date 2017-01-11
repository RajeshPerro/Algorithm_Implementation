#include "iostream"
#include "string"
#include "stdlib.h"
using namespace std;

void bf(char *T, char *p, int n, int m)
{
 for (int i = 0; i < n-m+1; ++i)
 {
 	int j = 0;
 	while(j<m && p[j] == T[i+j])
 	{
 		j++;
 	}
 	if (j==m)
 	{
 		cout<<"In broot force We have a Match at "<<i<<endl;
 	}
 }
}
void sunday(char *T, char *p, int n, int m)
{
	int skip[256];
	for (int i = 0; i < 256; ++i)
	{
		skip[i] = m+1;
	}
	for (int i = 0; i < m; ++i)
	{
		skip[(unsigned char)p[i]] = m-i;
	}
	for (int i = 0; i < n-m+1; i+= skip[(unsigned char)T[i+m]])//i+= skip[(unsigned char)p[i+m]]
	{
		int j=0;
		while(j<m && p[j] == T[i+j])
 		{
 			j++;
 		}
 		if (j==m)
 		{
 			cout<<"In Sunday We have a Match at "<<i<<endl;
 		}

	}
}


int main(int argc, char const *argv[])
{
	char *a="hello";
	char *b="ell";
	int len_n = strlen(a),len_m=strlen(b);
	cout<<len_n<<" " <<len_m<<endl;
	sunday(a,b,len_n,len_m);
	cout<<endl;
	bf(a,b,len_n,len_m);
	return 0;
}