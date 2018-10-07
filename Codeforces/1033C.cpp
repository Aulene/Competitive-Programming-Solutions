#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define mid (start + end) / 2
#define pi pair <int, int> 
#define ppi pair < pair <int, int>, int >

int a[100007], dp[100007];
vector <pi> vs;

bool cmp(pi a, pi b) {
    return a.f > b.f;
}

int check(int idx, int n) {
    if(idx >= 1 && idx <= n) return 1;
    return 0;
}

unordered_map <int, int> mx;

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, m, u, q, v, i, j, x, y, ans;
        memset(dp, -1, sizeof(dp));

        cin >> n;

        for(i = 1; i <= n; i++) {
            cin >> u;
            a[i] = u;
            // mx[u] = i;
            vs.pb({u, i});
        }

        sort(vs.begin(), vs.end(), cmp);

        // for(i = 0; i < vs.size(); i++) cout << vs[i].f << " " << vs[i].s << endl;
        // cout << endl;

        for(i = 0; i < vs.size(); i++)
            {
                u = vs[i].f;
                int idx = vs[i].s;

                // if(dp[idx] == -1) {
                //     dp[idx] = 1;
                // } else continue;

                // cout << vs[i].f << " " << vs[i].s << endl;

                // for(j = 1; j <= sqrt(u); j++)
                //     if(u % j == 0)
                //         {
                //             int div1 = j;
                //             int diff = abs(idx - mx[div1]);

                //             if(diff % div1 == 0) {
                //                 if(dp[idx] == 1) dp[mx[div1]] = 2;
                //                 else dp[mx[div1]] = 1;
                //             }

                //             cout << "DP[" << mx[div1] << "] = " << dp[mx[div1]] << " NUM = " << div1 << endl;

                //             div1 = u / j;

                //             if(div1 == u || div1 == j) continue;

                //             diff = abs(idx - mx[div1]);

                //             if(diff % div1 == 0) {
                //                 if(dp[idx] == 1) dp[mx[div1]] = 2;
                //                 else dp[mx[div1]] = 1;
                //             }
                        
                //             cout << "DP[" << mx[div1] << "] = " << dp[mx[div1]] << " NUM = " << div1 << endl;
                //         }

                ans = -1;

                for(j = 1;; j++) {
                    int pos = idx + j * u;
                    if(!check(pos, n)) break;
                    if(a[pos] > u && dp[pos] != -1) {
                        if(dp[pos] == 1) ans = 2;
                    }
                }

                for(j = 1;; j++) {
                    int pos = idx - j * u;
                    if(!check(pos, n)) break;
                    if(a[pos] > u && dp[pos] != -1) {
                        if(dp[pos] == 1) ans = 2;
                    }
                }

                if(ans == -1) ans = 1;

                dp[idx] = ans;
            }

        // for(i = 1; i <= n; i++) cout << dp[i] << " "; cout << endl;
        
        for(i = 1; i <= n; i++)
            if(dp[i] == 1) cout << "B";
            else cout << "A";

		return 0;   
	}