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

#define lli long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair

lli a[100007];
lli b[100007];
lli magicPowder, n;

lli check(lli cookies)
{
	lli i, powder=magicPowder;
	lli needPowder, ingNeeded;

	for(i=1; i<=n; i++)
		{	
			ingNeeded=cookies*a[i];

			if(ingNeeded > b[i])
				{
					needPowder=ingNeeded-b[i];

					if(powder<needPowder)
						return 0;
					powder-=needPowder;
				}
		}

	return 1;
}

lli bsearch()
{
	lli high=10000000007, low=0, mid;
	lli ans=0;

	while(low<=high)
		{
			mid=(low+high)/2;

			if(check(mid))
				{
					ans=mid;
					low=mid+1;
				}
			else
				high=mid-1;
		}

	return ans;
}

int main()
	{	
		int i;

		cin >> n >> magicPowder;

		for(i=1; i<=n; i++)
			cin >> a[i];

		for(i=1; i<=n; i++)
			cin >> b[i];

		cout << bsearch() << endl;
		return 0;
	}