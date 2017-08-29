#include <iostream>
using namespace std;
 
int main() 
{
	// your code goes here
		long int c,d,l;
		int flag;
		unsigned long int a,m;
		signed long int t;

		int n;
		cin>>n;
		for(int j=0;j<n;j++)
			{   
			    cin>>c>>d>>l;
				t=(2*d)-c;
				
				if(t>0)
					m=0;
				else
					m=t;
			 
			    a=d+m;
			 
				if(l>=(a*4)&&(l%4==0))
					flag=0;
				else
					flag=1;

				if(flag==0)
					cout<<"yes"<<endl;
				else
					cout<<"no"<<endl;
			}
 
	return 0;
}	