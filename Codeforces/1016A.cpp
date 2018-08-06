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

		int n, m, i, j, u, v = 0;

		cin >> n >> m;

		for(i = 0; i < n; i++) {
			cin >> u;

			u += v;
			cout << u / m << " ";
			v = u % m;
		}
		return 0;
	}