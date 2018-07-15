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

		int n, m, u, v, i, j, k, s, p;

		cin >> k >> n >> s >> p;

		int pack = s * p;

		u = k * n;
		
		// cout << pack << " " << u << endl;

		int ans = ceil(u / pack);

		cout << ans << endl;

		return 0;
	}