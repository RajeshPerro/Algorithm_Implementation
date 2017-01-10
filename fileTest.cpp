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
  

  ofstream myfile;
  myfile.open ("example.txt");
  timestamp_t t0 = get_timestamp();
  
  myfile << "Writing this to a file.\n";
  myfile.close();
  
  timestamp_t t1 = get_timestamp();
  double secs = (t1 - t0) / 1000000.0;

  cout<<"Required Time is : "<<secs<<endl;
  return 0;
}


    
