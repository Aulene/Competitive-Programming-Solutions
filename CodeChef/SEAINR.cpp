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

lli a[1007];

int lis(int l, int r) //Codeforces -- http://codeforces.com/blog/entry/13225 :P
{
    lli i, j, maxLength=0;
	multiset<int> s;
	multiset<int>::iterator it;

	for(i=l; i<=r; i++)
		{
			s.insert(a[i]);
			it=s.lower_bound(a[i]);

			it++;

			if(it!=s.end())
				s.erase(it);
		}

    return s.size();
}

int main()
	{
		int t, n, k, i, j;
		int cur, ans, l, r;

		cin >> t;

		while(t--)
			{
				cin >> n >> k;

				for(i=1; i<=n; i++)
					scanf("%lld", &a[i]);

				while(k--)
					{
						cin >> l >> r;
						ans=lis(l, r);
						cout << ans << endl;
					}
			}

		return 0;
	}