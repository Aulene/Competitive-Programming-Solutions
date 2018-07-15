#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second


signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, m, i, j, u = 0, v;

		cin >> n >> m;

		for(i = 0; i <= 100; i++)
			{
				v = pow(n, i);
				if(m >= v && v)
					u = i;
			}

		for(i = u; i >= 0; i--)
			{
				v = pow(n, i);
				if(m >= v)
					m -= v;
			}

		if(m) cout << "NO\n";
		else cout << "YES\n";
		return 0;
	}