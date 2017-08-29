#include <iostream>
#include <cstring>
using namespace std;

int main() {
	// your code goes here
	
	int i,j,t,n,k=0;
	int a[501];
	
	memset(a,0,sizeof(a));
	a[3]=1;
	for(i=4;i<=500;i++)
	{
		if(a[i]==1)
		continue;
		else
		{
			for(j=1;j<=i;j++)
			{
				if(a[j]!=1)
				if(j+i <= 500)
				a[j+i]=1;
			}
		}
	}
	
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(i=1; ;i++)
		{
			if(!a[i])
			{
			cout<<i<<" ";
			k++;
			}
			if(k==n)
			break;
		}
		cout<<endl;
		k=0;
	}
	return 0;
}