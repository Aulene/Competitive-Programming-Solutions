#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

int a[100007];
int pre[100007][7];

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, m, i, j, u, v;

		cin >> n >> m;

		for(i = 1; i <= n; i++) cin >> a[i];
		a[0] = 0;
		a[n + 1] = m;

		for(i = 1; i <= n; i++)
			{
				pre[i][0] = pre[i - 1][1]
			}
		return 0;
	}