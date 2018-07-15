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

		int n, i, j, u, v, ans = 0;

		cin >> n;
		
		for(i = 1; i <= n; i++)
			for(j = i; j <= n; j++)
				{
					u = i ^ j;
					if((u <= n) && (i + j > u) && (u >= j)) ans++;
				}

		cout << ans << endl;

		return 0;
	}