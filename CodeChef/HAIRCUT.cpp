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

lli x[107];
lli n;
lli a, b;

lli recur(lli m)
{
	lli i, l, r, num, j, ans=0;

	for(i=m; i<=x[n-1]+10; i++)
		{	
			l=i+a;
			r=i+b;
			num=0;

			for(j=0; j<n; j++)
				if(x[j]>=l && x[j]<=r)
					num++;

			ans=max(ans, num+recur(r+1));
		}

	return ans;
}
int main()
	{
		lli t, i, j;
		lli ans=0;

		cin >> t;

		while(t--)
			{
				cin >> n >> a >> b;

				for(i=0; i<n; i++)
					cin >> x[i];

				ans=recur(0);
				cout << ans << endl;
			}


		return 0;
	}