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

lli a[200005], d[200005];
lli n;

lli check(lli no)
{
	lli i, div;

	for(i=0; i<n; i++)
		{
			cout << no << " " << d[i] << endl;
			if(no>=1900)
				{
					if(d[i]==2)
						return 0;
				}
			else
				{
					if(d[i]==1)
						return 0;
				}

			no=no+a[i];
		}

	return no;
}

lli binarySearch()
{
	lli low=0, high=1000000, mid;
	lli ans=0, x;

	while(low<=high)
		{
			mid=(low+high)/2;

			x=check(mid);
			if(x!=0)
				{
					//cout << mid << endl;
					ans=max(x, ans);
					low=mid+1;
				}
			else
				high=mid-1;
		}

	return ans;
}
int main()
	{
		lli i, u, v, ans;

		cin >> n;
			
		for(i=0; i<n; i++)
			cin >> a[i] >> d[i];

		check(1901);
		cout << binarySearch() << endl;
		return 0;
	}