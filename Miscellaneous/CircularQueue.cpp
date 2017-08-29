#include<iostream>
#include<fstream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<climits>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<set>
#include<list>

using namespace std;

class circularQueue
{
	int *array;
	int size;
	int front, rear;

	public:
		circularQueue()
			{
				cout << "Enter the size of your queue\n";
				cin >> size;
				rear = front = -1;
				array = new int [size];
			}

		int push()
			{
				if(front >= size)
					{
						cout << "Overflow." << endl;
						return 0;
					}

				if(front==-1)
					front = rear = 0;

				cout << "Enter number:" << endl; 
				cin >> array[front];
				front++;
				return 0;
			}

		int pop()
			{
				if((rear==0 && front==0) || rear==-1 || front==-1)
					{
						cout << "Underflow" << endl;
						return 0;
					}

				cout << array[rear] << " being deleted." << endl;
				
				for(int i=0; i<front-1; i++)
					array[i]=array[i+1];
				front--;

				return 0;
			}

		int print()
			{
				if((rear==0 && front==0) || rear==-1 || front==-1)
					{
						cout << "Queue Empty." << endl;
						return 0;
					}

				cout << "Printing queue contents" << endl;
				for(int i=0; i<front; i++)
					cout << array[i] << " ";
				cout << endl;

				return 0;
			}
};

void menu()
{
	int choice;
	
	cout << "Circular Queue Version 1.0\n\n";
	circularQueue q;

	while(true)
		{
			cout << "1. Push\n2. Pop\n3. Print Queue\n";
			cin >> choice;

			switch(choice)
				{
					case 1: 
						q.push();
						break;
					case 2: 
						q.pop();
						break;
					case 3: 
						q.print();
						break;
					default: 
						return;
				}
		}
}
int main()
	{
		menu();
		return 0;
	}