#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

int dp[107][107];

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

        int n, m, t, i, j, u, v, k, ans = 0;
        
        dp[0][0] = 1;

        for(int i = 1; i <= 40; i++) {
            for(int j = 0; j <= 40; j++) {
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            }
        }

        // for(int i = 1; i < 5; i++) {
        //     for(int j = 1; j < 5; j++) {
        //         cout << dp[i][j] << " "; 
        //     } cout << endl;
        // }
    
        cin >> n >> m >> t;

        for(i = 4; i <= n; i++) {
            for(j = 1; j <= m; j++) {
                if(i + j == t) {

                    u = dp[n][i];
                    v = dp[m][j];

                    // cout << i << " " << j << " " << u << " " << v << endl;
                    ans = ans + u * v;

                }
            }
        }

        cout << ans << endl;

		return 0;
	}