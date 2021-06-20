#include<iostream>
#include <exception>
#include<string.h>
#include<bits/stdc++.h>
using namespace std;

#define UNICORN "1"
#define SHINE 	"2"

class HondaParent
{
	private:
	int iBikeCount; //Total bike count Honda Brand(Including color)

	public:
	HondaParent()
	{
		cout << "HondaParent default constructor." << endl;
	}
	
	HondaParent(const int &n)
	{
		cout << "HondaParent constructor." << endl;
		iBikeCount = n;
	}

	virtual int GetBikeCount()
	{
		cout << "HondaParent: GetBikeCount" << endl;		
		return iBikeCount;
	}
	
	virtual bool AddColor(const string& sColor)=0;
	virtual bool CheckColorAvailable(const string& sColor)=0;
	virtual ~HondaParent()
	{
		cout << "~HondaParent()" << endl;
	}

};

class PolyUnocorn: public HondaParent
{
	private:
	int iBikeCount;
	vector<string> vUnocornColor; //list of available unicorn bike color

	public:
	PolyUnocorn()
	{
		cout << "PolyUnocorn default constructor." << endl;
	}
	
	PolyUnocorn(const int& n)
	{
		cout << "PolyUnocorn constructor." << endl;
		iBikeCount = n;
	}

	int GetBikeCount()
        {
        	cout << "PolyUnocorn: GetBikeCount " << endl;
                return iBikeCount;
        }
        
        
        bool AddColor(const string& sColor)
	{
		cout << "AddColor from PolyUnocorn class" << endl;
		try
		{
			vUnocornColor.push_back(sColor);
			return true;	
		}
		catch(std::bad_alloc)
		{
			cout << "push_back fail while adding color." << endl;
			return false;
		}
	}

	bool CheckColorAvailable(const string& sColor)
	{
		cout << "CheckColorAvailable from PolyUnocorn class" << endl;
		
		vector<string>::iterator it;
		it = find(vUnocornColor.begin(), vUnocornColor.end(), sColor);
		
		if(it != vUnocornColor.end())
		{
			cout << sColor << ": color is available" << endl;
			return true;
		}
		else
		{
			cout << sColor << ": color is not available" << endl;
			return false;
		}
	}

	~PolyUnocorn()
	{
		cout << "~PolyUnocorn()" << endl;
	}
};


class PolyShine: public HondaParent
{
	private:
	int iBikeCount;
	vector<string> vShineColor; //list of available Shine bike color
	
	public:
	PolyShine()
	{
		cout << "PolyShine default constructor." << endl;
	}
	
	PolyShine(const int& n)
	{
		cout << "PolyShine constructor." << endl;
		iBikeCount = n;
	}

	int GetBikeCount()
        {
        	cout << "PolyShine: GetBikeCount " << endl;
                return iBikeCount;
        }

	bool AddColor(const string& sColor)
	{
		cout << "AddColor from PolyShine class" << endl;
		try
		{
			vShineColor.push_back(sColor);
			return true;	
		}
		catch(std::bad_alloc)
		{
			cout << "push_back fail while adding color." << endl;
			return false;
		}
	}

	bool CheckColorAvailable(const string& sColor)
	{
		cout << "CheckColorAvailable from PolyShine class" << endl;
		
		vector<string>::iterator it;
		it = find(vShineColor.begin(), vShineColor.end(), sColor);
		
		if(it != vShineColor.end())
		{
			cout << sColor << ": color is available" << endl;
			return true;
		}
		else
		{
			cout << sColor << ": color is not available" << endl;
			return false;
		}
	}

	~PolyShine()
	{
		cout << "~PolyShine() Destructor" << endl;
	}
};


int main(int argc, char *argv[])
{
	HondaParent* poParent = NULL;
	//bool b = true;
	printf("Number of argument id: %d\n", argc);
	
	if(argc > 1)
	{
		try
		{
			if(strcmp(argv[1], UNICORN) == 0)
			{	
				poParent = new PolyUnocorn(10);		
			}
			else (strcmp(argv[1], SHINE) == 0)
			{
				poParent = new  PolyShine(4);
			}
		}
		catch(std::bad_alloc)
		{
			cout << "new fail to allocate memory." << endl;
			poParent = NULL;
			return -1;
		}
			
		int iCountIs = poParent->GetBikeCount();
		cout << "Count is: " << iCountIs << endl;
		
		if(poParent->AddColor("Black"))
		{
			cout << "Add color is successfull" << endl;
		}
		
		if(poParent->CheckColorAvailable(argv[2]))
		{
			cout << argv[2] << "Color is available" << endl;
		}
		

		delete poParent;
	}
	else
	{
		printf("please set which bike count you want to check\n");
	}
	
	return 0;
}
