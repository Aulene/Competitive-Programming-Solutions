#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

int a[107];
int dp[107][107];
bool xr[107][107];

int countOnes(int n) 
{
    int count = 0;
    while (n != 0)
    {
        n = n & (n - 1);
        count++;
    }
    return count % 3;
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, m, i, j, u, v, k, ans = 0;

		cin >> n >> m;

		for(i = 1; i <= n; i++) cin >> a[i];

		for(i = 1; i <= n; i++) 
			for(j = 1; j <= n; j++)
				xr[i][j] = !countOnes(a[i] xor a[j]);

		// for(i = 1; i <= n; i++) 
		// 	{
		// 		for(j = 1; j <= n; j++)
		// 		cout << i << " " << j << " " << countOnes(a[i] xor a[j]) << " " << (a[i] xor a[j]) << " " << xr[i][j] << " " << endl; cout << endl;
		// 	}


		if(m > n) {
			cout << 0 << endl;
			return 0;
		}

		for(i = 1; i <= n; i++) dp[i][1] = 1;

		for(i = 2; i <= m; i++)
			{
				for(j = 1; j <= n; j++)
					for(k = j + 1; k <= n; k++)
						if(xr[j][k])
							dp[k][i] = (dp[k][i] + dp[j][i - 1]) % mod; 
			}

		for(i = 1; i <= n; i++) ans += dp[i][m];

		cout << ans << endl;
 		return 0;
	}