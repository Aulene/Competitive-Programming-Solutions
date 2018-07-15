#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

int a[1000007];

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int i, j, u, v, n, ans = 0, claw;

		cin >> n;

		for(i = 1; i <= n; i++) cin >> a[i];

		claw = n - a[n];

		for(i = n - 1; i >= 1; i--)
			{	
				if(i >= claw) ans++;
				claw = min(claw, i - a[i]);
			}

		cout << n - ans << endl;

		return 0;
	}