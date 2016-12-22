#include "iostream"

using namespace std;

class BST
{
	int size;

	struct node
	{
		struct node * parent,lc,rc;
		int key ;
		~node();
		node(struct node *p, int k);

	}; *root;
	void print_helper(struct node *r);
public:
	int getize();
	bool find(int key);
	void insert(int key);
	void remove(int key);
	void print();
	int getmin();
	int gemax();

	BST();
	~BST();
	
};
BST::BST()
{
	size = 0;
	root = NULL;
}
BST::~BST()
{

	if (root)
	{
		delete root;
	}
}
int BST::getize()
{
	return size;
}

BST::node::~node()
{
	if (lc)
	{
		delete lc;
	}
	if (rc)
	{
		delete rc;
	}
}

BST::node::node(node *p, int k)
{
	parent = p;
	lc = rc = NULL;
	key = k;
}

bool BST::find(int key)
{
	struct node *ptr = root;
	while(ptr)
	{
		if (ptr->key == key) 
		{
			return true;
		}
		else if (ptr->key < key)
		{
			ptr = ptr->rc;
		}
		else
		{
			ptr = ptr->lc;
		}
	}
return false;
}

void BST::insert(int key)
{
	if (find(key))
	{
		return;
	}
	if (!root)
	{
		root = new node(NULL,key);
	}
	struct node *ptr = root;
	while(true)
	{
		if (ptr->key >key)
		{
			if (ptr->lc)
			{
				ptr = ptr->lc;
			}
			else
			{
				ptr->lc = new node(ptr,key)
				break;
			}
		}
		else 
		{	
			if (ptr->rc)
			{
				ptr = ptr->rc;	
			}
			else
			{
				ptr->rc = new node(ptr,key);
				break;
			}
			
		}
	}
	size++;
}
void BST::remove(int key)
{
	if (!find(key))
	{
		return;
	}
	struct node *ptr = root, *victim;
	
	while(ptr)
	{
		if (ptr->key == key)
		{
			break;
		}
		else if (ptr->key < key)
		{
			ptr = ptr->rc;
		}
		else{
			ptr = ptr->lc;
		}

		if (ptr -> lc)
		{
			victim = ptr->lc;
			while(victim->rc)
			{
				victim = victim->rc;
			}
			ptr->key = victim->key;
			if (victim == victim->parent->rc )
			{
				victim->parent->rc = victim->lc;
			}
			else{
				victim->parent->lc = victim->lc;
			}
			victim->lc = NULL;
			delete victim;
		}
		else
		{
			if (ptr->rc)
			{
				victim = ptr->rc;
				while(victim->lc)
				{
					victim = victim->lc;
				}
				ptr->key = victim->key;
				if (victim == victim->parent->rc )
				{
					victim->parent->rc = victim->lc;
				}
				else{
					victim->parent->lc = victim->rc;
				}
				victim->rc = NULL;
				delete victim;
			}
			else
			{
				if (ptr !=root)
				{
					if (ptr == ptr->parent->rc)
					{
						ptr->parent->rc = NULL;
					}
					else
					{
						ptr->parent->lc = NULL;
					}
				}
				else
				{
					root = NULL;
				}
			delete ptr;	
			}
		}

	}
}

void BST::print_helper(struct node *r)
{
	if (r == NULL)
	{
		cout <<" - "<<endl;
		return
	}

	cout<<"(";
	print_helper(r->lc);
	cout<<":"<<r->key<<":";
	print_helper(r->rc);
	cout<<")";

}
void BST::print()
{
	print_helper(root);
	cout<<endl;
}

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}