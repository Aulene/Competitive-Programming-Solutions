#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

int a[207];

int lisfirst(int n)
{
	multiset <int> s;
	multiset <int> :: iterator it;
	int ans = 0;

	for(int i = 1; i <= n; i++)
		{
			s.insert(a[i]);

			it = s.upper_bound(a[i]);
			if(it != s.end()) {
				ans++;
				s.erase(it);
			}
		}

	


}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int t, n, i, j, u, v;

		cin >> t;

		while(t--)
			{
				cin >> n;

				for(i = 1; i <= n; i++) cin >> a[i];


			}
		return 0;
	}