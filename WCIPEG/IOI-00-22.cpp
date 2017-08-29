#include<iostream>
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
#define pb push_back

int n;
lli a[100007];

lli recur(int index, lli prev)
{
	if(index>=n)
		return 0;

	int i, k;
	lli ans=0;

	for(i=index; i<n; i++)
		{
			k=__gcd(prev, a[i]);

			if(k>1)
				ans=max(ans, 1+recur(i+1, a[i]));
		}

	ans=max(ans, recur(index+1, a[index]));
	return ans;
}

int main()
	{
		int t, i;
		lli ans;

		cin >> t;

		while(t--)
			{
				cin >> n;

				for(i=0; i<n; i++)
					cin >> a[i];

				ans=recur(0, a[0]);
				cout << ans << endl;
			}

		return 0;
	}