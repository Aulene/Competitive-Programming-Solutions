#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

ld ent[2007], lv[2007];

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, t, i, j, u, v;
		long double p, ans = 0;

		cin >> n >> p >> t;

		ent[0] = lv[0] = 1;
		ent[1] = p; lv[1] = (ld) 1 - p;
		for(i = 2; i <= 2000; i++) ent[i] = ent[i - 1] * p;
		for(i = 2; i <= 2000; i++) lv[i] = lv[i - 1] * lv[1];
		
		for(i = 0; i <= n; i++) {
			ans = ans + (ld) ent[i] * lv[t - i];
		}

		ans = (ld) ans / (n + 1);
		
		printf("%.16Lf\n", ans);
		return 0;
	}