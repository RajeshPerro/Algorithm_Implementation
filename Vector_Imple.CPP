#include "iostream"
#include <algorithm>
#include <fstream>
#include <sys/time.h>

using namespace std;

class Vetki
{

	int vsize, maxsize;
	int* store;
	void alloc_new();

	public:
	Vetki();
	Vetki(int);
	Vetki(const Vetki&); //Copy Constructor.
	~Vetki();
	void push_back(int);
	void pop_back();
	int size();
	int operator[](int);
	int at(int i);
	void erase_one(int);
	void erase_seg(int, int);
	void resize(int);
	void resize(int,int);

	//Want to test operator overloading.. :) 
	Vetki& operator=(const Vetki&);

	
	
};
/*Simeple Constructor to intialize "Maximum" size, VectorSize and the store array*/
Vetki::Vetki()
{
	maxsize = 20;
	store = new int[maxsize];
	vsize = 0;

}
Vetki::Vetki(int i)
{
	maxsize = i;
	store = new int[maxsize];
	vsize = 0;
}

Vetki::Vetki(const Vetki& v )
{
	
		maxsize = v.maxsize;
		vsize = v.vsize;
		store = new int[maxsize];
		for (int i = 0; i < v.vsize; ++i)
		{
			store[i] = v.store[i];
		}
}

Vetki::~Vetki()
{
	delete[] store;
}

void Vetki::push_back(int val)
{
	if ( vsize+1 > maxsize )
	{
		alloc_new();
	}
	store[vsize]=val;
	vsize++;
}

/* If the size exist then we are just making the size double*/

void Vetki::alloc_new()
{
	maxsize = vsize * 2;
	int* nstore = new int[maxsize];
	for (int i = 0; i < vsize; ++i)
	{
		nstore[i] = store[i];
	}
	delete[] store;
	store = nstore;
}

void Vetki::pop_back()
{
	vsize--;

	if (vsize < maxsize/4 && maxsize > 32)
	{
		maxsize = maxsize/2;
		
	}	
	int *nstore = new int[maxsize];
	for (int i = 0; i < vsize; ++i)
		{
			nstore[i] = store[i];
		}
	delete []store;
	store = nstore;
}


int Vetki::size()
{
	return vsize;
}

/*Implemneting array reference*/

int Vetki:: operator[](int val)
{
	return store[val];
}

/* Returing the posting of array/store */

int Vetki::at(int i)
{
	if ( i < vsize )
	{
		return store[i];
	}
	
}

Vetki& Vetki::operator=(const Vetki& v) 
{
	if ( this != &v)
	{
		maxsize = v.maxsize;
		vsize = v.vsize;
		delete[] store;
		for (int i = 0; i < v.vsize; ++i)
		{
			store[i] = v.store[i];
		}
	}
return *this;	
}

void Vetki::erase_one(int position)
{
	//int left_size = 0+position;
	//int right_size = vsize - position;
	//cout<<"Left Size = "<<left_size<<"  Right Size = "<<right_size<<endl;
	int left_size = 0, right_size = 0;
	unsigned ij,ik;
	if (position > vsize || position < 0)
	{
		cout<<"Sorry.!! Invalid Position.\n";
		return;
	}
	else if (position !=0 || position > 0)
	{
		// int *nstore_left = new int[left_size];
		// for (int i = 0; i < position; ++i)
		// {
		// 	nstore_left[left_size] = store[i];
		// 	left_size++;
			
		// }
		
		// int *nstore_right = new int[right_size];
		
		// for (int c = position+1; c < vsize; ++c)
		// {
		// 	nstore_right[right_size] = store[c];
		// 	right_size++;
			
		// }
		
		
		// //Checking the copied values
		// cout<<"Left Array"<<endl;
		// for (int j = 0; j < left_size; ++j)
		// {
		// 	cout<<nstore_left[j]<<" ";
		// }
		// cout<<endl<<"Right Array"<<endl;
		// for (int k = 0; k < right_size; ++k)
		// {
		// 	cout<<"position = "<<k<<" & Value = "<<nstore_right[k]<<" ";
		// }
		// cout<<endl;
		// cout<<"Left : "<<left_size<<" Right : "<<right_size<<endl;

		// int* all = new int[ left_size + right_size ];
		
		// for (ij = 0; ij < left_size; ++ij)
		// {
		//     all[ij] = nstore_left[ij];
		// }
		// for (ik = 0; ik < right_size; ik++)
		// {	//cout<<"ik = "<<ik<<" Value = "<<nstore_right[ik]<<" ";
		//     all[ij++] = nstore_right[ik];
		//     cout<<endl;
		//     //cout<<"ij = "<<ij<<" Value in all = "<<all[ij]<<" ";
		// }
		// cout<<"<<<---Elements in all[] --->>>";
		// for (int i = 0; i <(left_size+right_size); ++i)
		// {
		// 	cout<<all[i]<<" ";
		// }
		// cout<<endl;
		// //copy( nstore_left,  nstore_left + left_size, all);
	 //    //copy( nstore_right, nstore_right+right_size, all + left_size); 
	
		// delete []store;
		// store = all;
		// delete[] nstore_left;
		// delete[] nstore_right;
		// delete[] all;
		// vsize--;

		int* nstore = new int[maxsize];
		int j=0;
		for (int i = 0; i < vsize; i++)
		{
			if(i != position)
			{
				nstore[j++] = store[i];
			}
			else
			{
				i=i;
			}

		}
		
		delete[] store;
		store = nstore;
		vsize--;
		
	}
	else
	{
		int* nstore = new int[maxsize];
		int j=0;
		for (int i = 1; i < vsize; i++)
		{
			if(i != position)
			{
				nstore[j++] = store[i];
			}
			else
			{
				i=i;
			}

		}
		
		delete[] store;
		store = nstore;
		vsize--;
	}
}

void Vetki::erase_seg(int first, int last)
{
	int* nstore = new int[maxsize];
	int num_of_elements = (last - first)+1;
	int j=0;
	if (first > vsize || last > vsize || first < 0 || last < 0)
	{
		cout<<"Sorry.!! Invalid Position.\n";
		return;

	}
	else
	{
		for (int i = 0; i < vsize; ++i)
		{
			if (i != first)
			{
				nstore[j++] = store[i];
			}

			else
			{
				if (i != vsize)
				{
					i=last;
				}
				else
				{
					i=vsize;
				}
			}

		}
		delete[] store;
		store = nstore;
		for (int no_e = 0; no_e < num_of_elements; no_e++)
		{
			vsize--;
		}
	}	
	
}

void Vetki::resize(int n)
{
	int* nstore;	
	int cp_j=0,old_vec_size = vsize;
	int resize_num = 0;
	if ( n < 0)
	{
		cout<<"Sorry.!! Invalid Position.\n";
		return;
	}
	else if (n > vsize )
	{
		
		nstore = new int[n];

		for (int i = 0; i < vsize; ++i)
		{
			nstore[cp_j++] = store[i];
		}

		for (int no_e = old_vec_size; no_e < n; no_e++)
		{
			vsize++;
			nstore[cp_j++] = 0;
		}
	}
	else if (n == vsize)
	{
		cout<<"Your vector has already "<<n<<" elements.";
		return;
	}
	else 
	{
		//cout<<"Testing....this condition..";
		nstore = new int[n];
		for (int i = 0; i < n; ++i)
		{
			nstore[resize_num++] = store[i];
		}
		for (int no_e = 0; no_e < (old_vec_size-n) ; no_e++)
		{
			vsize--;
		}
	}

	delete[] store;
	store = nstore;
	
}

void Vetki::resize(int n, int num)
{
	int* nstore;	
	int cp_j=0,old_vec_size = vsize;
	int resize_num = 0;
	if ( n < 0)
	{
		
		return resize(n);
	}
	else if (n > vsize )
	{
		cout<<"I am working.!\n";

		nstore = new int[n];

		for (int i = 0; i < vsize; ++i)
		{
			nstore[cp_j++] = store[i];
		}

		for (int no_e = old_vec_size; no_e < n; no_e++)
		{
			vsize++;
			// push_back(num);
			// cout<<"Fucking Number is : " <<num;
			// // vsize++;
			 nstore[cp_j++] = num;
		}
	}
	else if (n == vsize)
	{
		
		return resize(n);
	}
	else
	{
		//cout<<"Testing....this condition..";
		return resize(n);
	}

	delete[] store;
	store = nstore;
}

typedef unsigned long long timestamp_t;
  static timestamp_t
    get_timestamp ()
    {
      struct timeval now;
      gettimeofday (&now, NULL);
      return  now.tv_usec + (timestamp_t)now.tv_sec * 1000000000;
    }

int main(int argc, char const *argv[])
{
	ofstream testFile;
	Vetki vec;
	Vetki vec3;
	int a=1,how_many;
	double secs=0;
	cout<<"Please enter starting number of elements :  ";
	cin>>how_many;
	/*---START PUSH BACK in VECTOR---*/
	testFile.open("VectorData.txt",ofstream::out | std::ofstream::app);
	timestamp_t t0 = get_timestamp();
	while(a<=how_many)
	{
		// cin>> a;
		// if (a == -1)
		// {
		// 	break;
		// }
		vec.push_back(a);
		timestamp_t t1 = get_timestamp();
  		secs+= (t1 - t0) / 1000000.0;

		a++;
	}
	testFile<<"Time for "<<how_many<<" elements : "<<secs*1000 <<" Millisecond"<<endl;
	int b=1;
	how_many = how_many*2;
	secs=0;
	timestamp_t t2 = get_timestamp();
	while(b<=how_many)
	{
		// cin>> a;
		// if (a == -1)
		// {
		// 	break;
		// }
		vec.push_back(b);
		timestamp_t t3 = get_timestamp();
  		secs+= (t3 - t2) / 1000000.0;

		b++;
	}
	testFile<<"Time for "<<how_many<<" elements : "<<secs*1000 <<" Millisecond"<<endl;
	
	int c=1;
	how_many = how_many*2;
	secs=0;
	timestamp_t t4 = get_timestamp();
	while(c<=how_many)
	{
		// cin>> a;
		// if (a == -1)
		// {
		// 	break;
		// }
		vec.push_back(c);
		timestamp_t t5 = get_timestamp();
  		secs+= (t5 - t4) / 1000000.0;

		c++;
	}
	testFile<<"Time for "<<how_many<<" elements : "<<secs*1000 <<" Millisecond"<<endl;

	int d=1;
	how_many = how_many*2;
	secs=0;
	timestamp_t t6 = get_timestamp();
	while(d<=how_many)
	{
		// cin>> a;
		// if (a == -1)
		// {
		// 	break;
		// }
		vec.push_back(d);
		timestamp_t t7 = get_timestamp();
  		secs+= (t7 - t6) / 1000000.0;

		d++;
	}
	testFile<<"Time for "<<how_many<<" elements : "<<secs*1000<<" Millisecond"<<endl;

	int e=1;
	how_many = how_many*2;
	secs=0;
	timestamp_t t8 = get_timestamp();
	while(e<=how_many)
	{
		// cin>> a;
		// if (a == -1)
		// {
		// 	break;
		// }
		vec.push_back(e);
		timestamp_t t9 = get_timestamp();
  		secs+= (t9 - t8) / 1000000.0;

		e++;
	}
	testFile<<"Time for "<<how_many<<" elements : "<<secs*1000<<" Millisecond"<<endl;
	
	testFile.close();
	
	/*---End of VECTOR INPUT---*/


	cout<<"You have enter "<<vec.size() <<" elements.\n";

	for (int i = 0; i < vec.size(); ++i)
	{
		cout << vec[i] <<" ";
	}	

	cout<<endl<<endl;
	vec.pop_back();
	cout<<"After pop_back your vector size is "<<vec.size()<<endl;
	for (int i = 0; i < vec.size(); ++i)
	{
		cout << vec[i] <<" ";
	}
	cout<<endl<<endl;
	//Erasing one postion.. :) 
	int pos;
	cout<<"which position you want to erase (remember it's start from 0) : ";
	cin>>pos;
	vec.erase_one(pos);
	cout<<"After performing erase() method your vector size is : "<<vec.size()<<endl;
	for (int i = 0; i < vec.size(); ++i)
	{
		cout << vec[i] <<" ";
	}
	cout<<endl<<endl;
	
	//Testing erase_seg() method.
	int pos1,pos2;
	cout<<"which positions (segment) you want to erase (remember it's start from 0) : ";
	cin>>pos1>>pos2;
	vec.erase_seg(pos1,pos2);
	cout<<"After performing erase_seg() method your vector size is : "<<vec.size()<<endl;
	for (int i = 0; i < vec.size(); ++i)
	{
		cout << vec[i] <<" ";
	}
	cout<<endl<<endl;
	

	//Testing resize() method with one parameter.
	int num;
	cout<<"Please input your number to resize your vector : ";
	cin>>num;
	vec.resize(num);
	cout<<"After performing resize(with one parameter) method your vector size is : "<<vec.size()<<endl;
	for (int i = 0; i < vec.size(); ++i)
	{
		cout << vec[i] <<" ";
	}
	cout<<endl<<endl;

	//Testing resize() method with two parameters.
	int posi,num_be_push;
	cout<<"From which positions you want to resize and which number you wanna push (remember it's start from 0) : ";
	cin>>posi>>num_be_push;
	vec.resize(posi,num_be_push);
	cout<<"After performing resize(with two parameters) method your vector size is : "<<vec.size()<<endl;
	for (int i = 0; i < vec.size(); ++i)
	{
		cout << vec[i] <<" ";
	}
	cout<<endl<<endl;

	//Testing out copy constructor
	cout<<"Copy constructor working.!!"<<endl;
	Vetki vec2(vec);
	for (int i = 0; i < vec2.size(); ++i)
	{
		cout << vec2[i] <<" ";
	}
	cout<<endl;

	//Testing the assignment operator.
	cout<<"Assignment operator Testing.."<<endl;
	vec3 = vec;
	for (int i = 0; i < vec3.size(); ++i)
	{
		cout << vec3[i] <<" ";
	}
	cout<<endl;
	return 0;
}