#include <iostream>
#include <vector>
using namespace std;
int main ()
{
  std::vector<int> myvector;

  // set some initial content:
  for (int i=1;i<10;i++) myvector.push_back(i);
  int num;
  cin>>num;
  myvector.resize(num);
  //myvector.resize(8,100);
  //myvector.resize(12);
 

  std::cout << "myvector contains:";
  for (int i=0;i<myvector.size();i++)
    std::cout << ' ' << myvector[i];
  std::cout << '\n';

  return 0;
}
