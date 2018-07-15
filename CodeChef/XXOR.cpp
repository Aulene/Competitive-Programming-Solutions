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
int bitz[100007][37];

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, m, q, i, j, l, r, v, ans;
		int u = pow(2, 31) - 1;

		// cout << u << endl;

		cin >> n >> q;

		for(i = 1; i <= n; i++) cin >> a[i];
		
		for(i = 1; i <= n; i++)
			{
				v = a[i];

				for(j = 0; j < 31; j++)
					{
						bitz[i][j] = v % 2;
						v /= 2;
 					}
			}

		for(i = 2; i <= n; i++)
			for(j = 0; j < 31; j++)
				bitz[i][j] += bitz[i - 1][j];
			
		while(q--)
			{
				ans = 0;

				cin >> l >> r;

				v = 1, m = (r - l + 1);

				for(i = 0; i < 31; i++)
					{
						int a = bitz[r][i] - bitz[l - 1][i];
						int diff = m - a;
						// cout << a << " " << diff << " " << v << " " << ans << endl;

 						if(a < diff) ans += v;
						v *= 2;
					}

				cout << ans << endl;
			}
		return 0;
	}