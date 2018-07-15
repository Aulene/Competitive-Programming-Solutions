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

		int n, m, i, j, u, v;

		cin >> n >> m;

		cout << min(n, m) + 1 << endl;
		for(i = 0; i <= min(n, m); i++)
			cout << i << " " << m - i << endl;

		return 0;
	}