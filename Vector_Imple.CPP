#include "iostream"
#include <algorithm>

using namespace std;

#define LEN( a ) (sizeof( a ) / sizeof( a[ 0 ] ))

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
	void erase_one(int);
	void erase_seg(int, int);

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

void Vector_Imple::erase_one(int position)
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