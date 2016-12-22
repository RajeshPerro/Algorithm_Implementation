#include <iostream>
using namespace std;

int main()
  {
  int odd[]  = { 1, 3, 5 };
  int even[] = { 2, 4, 6 };
  unsigned j ;

  int* all = new int[6];

  // Here's a simple way of doing it... ;-)
  for ( j = 0; j < 3; ++j)
  {
    all[j] = odd[j];
  }
  for (unsigned i = 0; i < 3; ++i)
  {
    all[j++] = even[i];
  }
  for (int ik = 0; ik < 6; ++ik)
  {
    cout<<all[ik]<<" ";
  }
  cout<<endl;
  return 0;
  }