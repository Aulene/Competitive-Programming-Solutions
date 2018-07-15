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

		int n, i, j, u, v;

		cin >> n;

		u = 3;

		for(int i = 1; i <= n; i++)
			{
				cout << u << " " << i << endl;
				u += u;
			}
		return 0;
	}