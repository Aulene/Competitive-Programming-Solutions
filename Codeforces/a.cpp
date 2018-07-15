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

		int t, n, i, j, u, v, w, ans = 0;
		int x, y;

		w = 0;

		cin >> n;

		for(i = 0; i < n; i++)
			{
				cin >> y >> x;
				w = (y * 100) / (100 + x);
				cout << w << endl;

			}


		return 0;
	}