#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

long double a[100007];
int dp[10007];

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, i, j, u, v;

		cin >> n;

		for(i = 1; i <= n; i++)
			{
				cin >> u >> v;
				a[i] = u * u * v;
			}
		return 0;
	}