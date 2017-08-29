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

lli n, m, k;

bool check(lli mid)
{
	lli firstTermS1=mid-k+1, firstTermS2=mid;
	lli sumS1, sumS2;

	sumS1=k/2*(firstTermS1+1);
	sumS2=(k-1)/2*(firstTermS2+1);
	lli sum=sumS1+sumS2;

	cout << mid << " " << sum << endl;
	if(sum>m)
		return 0;
	return 1;
}

lli bsearch()
{
	lli low=1, high=m;
	lli mid, ans=1;

	while(low<=high)
		{
			mid=(low+high)/2;

			if(check(mid))
				{
					ans=mid;
					low=mid+1;
				}
			else
				{
					high=mid-1;
				}
		}

	return ans;
}

int main()
	{
		lli i;
		lli ans;

		cin >> n >> m >> k;

		cout << bsearch() << endl;
		return 0;
	}