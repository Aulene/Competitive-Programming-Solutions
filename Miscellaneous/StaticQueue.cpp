#include<iostream>

using namespace std;

#define lli long long int
#define mod 1000000007
#define pb push_back

class StaticQueue
{
	int a[107];
	int top;
	int rear;

	public:
		StaticQueue()
			{
				top=0;
				rear=0;
			}	
		int insert(int n);
		int display();
		int del();
};

int StaticQueue::insert(int n)
{
	a[top]=n;
	top++;
	return 0;
}

int StaticQueue::display()
{
	int i;
	for(i=0; i<top; i++)
		printf("Display [%d]: [%d]\n", i, a[i]);
	return 0;
}

int StaticQueue::del()
{
	int i;
	cout << "Element Deleted" << endl;

	for(i=0; i<top; i++)
		a[i]=a[i+1];
	top--;

	return 0;
}

StaticQueue x;

int main()
	{
		int n, op, val;

		cin >> n;

		while(n--)
			{
				cin >> op;

				if(op==1)
					{
						cin >> val;
						x.insert(val);
					}
				else if(op==2)
					x.del();
				else
					x.display();
			}

		return 0;
	}