#include<iostream>

using namespace std;

class StaticStack
{
	int a[107];
	int top;

	public:
		StaticStack()
			{
				top=0;
			}

		int push(int n);	
		int pop();
		int display();	
};


int StaticStack::push(int n)
{
	a[top]=n;
	top++;
	return 0;
}	

int StaticStack::pop()
{
	if(top==0)
		return 0;

	cout << "POPPED " << a[top-1] << endl;
	top--;
	return 0;
}

int StaticStack::display()
{
	if(top==0)
		return 0;

	int i;
	
	for(i=0; i<top; i++)
		printf("Element [%d]: %d\n", i, a[i]);
	return 0;
}

StaticStack x;

int main()
	{
		int n, op, ret;
		int val;

		cin >> n;

		while(n--)	
			{
				cin >> op;

				if(op==1)
					{
						cin >> val;
						x.push(val);
						cout << "PUSHED" << endl;
					}
				else if(op==2)
					x.pop();
				else
					x.display();
			}
		return 0;
	}