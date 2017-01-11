#include <iostream>
#include <fstream>
#include <sys/time.h>

using namespace std;
typedef unsigned long long timestamp_t;
  static timestamp_t
    get_timestamp ()
    {
      struct timeval now;
      gettimeofday (&now, NULL);
      return  now.tv_usec + (timestamp_t)now.tv_sec * 1000000000;
    }

int main () 
{
  double secs=0;
  int i =1;

  ofstream myfile;
  myfile.open ("example.txt");
  timestamp_t t0 = get_timestamp();
  while(i<=500)
  {
  	myfile << "Writing this to a file.\n";
  	timestamp_t t1 = get_timestamp();
  	secs+= (t1 - t0) / 1000000.0;
  	i++;
  }
  myfile.close();
  

  cout<<"Required Time is : "<<secs*1000<<endl;
  return 0;
}


    
