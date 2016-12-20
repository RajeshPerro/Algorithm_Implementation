#include "iostream"

using namespace std;

class Vector_Imple
{

	int vsize, maxsize;
	int* store;
	void alloc_new();

	public:
	Vector_Imple();
	Vector_Imple(int);
	Vector_Imple(const Vector_Imple&); //Copy Constructor.
	~Vector_Imple();
	void push_back(int);
	void pop_back();
	int size();
	int operator[](int);
	int at(int i);

	//Want to test operator overloading.. :) 
	Vector_Imple& operator=(const Vector_Imple&);

	
	
};
/*Simeple Constructor to intialize "Maximum" size, VectorSize and the store array*/
Vector_Imple::Vector_Imple()
{
	maxsize = 20;
	store = new int[maxsize];
	vsize = 0;

}
Vector_Imple::Vector_Imple(int i)
{
	maxsize = i;
	store = new int[maxsize];
	vsize = 0;
}

Vector_Imple::Vector_Imple(const Vector_Imple& v )
{
	
		maxsize = v.maxsize;
		vsize = v.vsize;
		store = new int[maxsize];
		for (int i = 0; i < v.vsize; ++i)
		{
			store[i] = v.store[i];
		}
}

Vector_Imple::~Vector_Imple()
{
	delete[] store;
}

void Vector_Imple::push_back(int val)
{
	if ( vsize+1 > maxsize )
	{
		alloc_new();
	}
	store[vsize]=val;
	vsize++;
}

/* If the size exist then we are just making the size double*/

void Vector_Imple::alloc_new()
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

void Vector_Imple::pop_back()
{
	vsize--;

	if (vsize < maxsize/4 && maxsize > 32)
	{
		maxsize = maxsize/2;
		int *nstore = new int[maxsize];
		for (int i = 0; i < vsize; ++i)
		{
			nstore[i] = store[i];
		}
		delete []store;
		store = nstore;
	}	
}


int Vector_Imple::size()
{
	return vsize;
}

/*Implemneting array reference*/

int Vector_Imple:: operator[](int val)
{
	return store[val];
}

/* Returing the posting of array/store */

int Vector_Imple::at(int i)
{
	if ( i < vsize )
	{
		return store[i];
	}
	
}

Vector_Imple& Vector_Imple::operator=(const Vector_Imple& v) 
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

int main(int argc, char const *argv[])
{
	Vector_Imple vec;
	Vector_Imple vec3;
	int a;
	while(EOF)
	{
		cin>> a;
		if (a == -1)
		{
			break;
		}
		vec.push_back(a);
	}
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
	//Testing out copy constructor
	cout<<"Copy constructor working.!!"<<endl;
	Vector_Imple vec2(vec);
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