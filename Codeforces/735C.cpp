#include<iostream>
#include<algorithm>

using namespace std;

#define lli long long int

lli a[107];

int main()
{
	lli n, i, u;

	cin >> n;

	a[1]=2;
	a[2]=3;

	for(i=3; i<=106; i++)
		a[i]=a[i-1]+a[i-2];

	u=1;

	while(a[u+1]<=n)
		u++;

	cout << u << endl;
	return 0;
}