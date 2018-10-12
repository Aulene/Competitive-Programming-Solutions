#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define mod 998244353
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define mid (start + end) / 2
#define pi pair <int, int> 
#define ppi pair < pair <int, int>, int >

int ones[200007];

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
        cout.tie(NULL);

        int n, m, i, j, u, v, ans = 0;
        string a, b;

        int px = 1;
        u = 0;

        cin >> n >> m;
        cin >> a >> b;

        reverse(b.begin(), b.end());

        for(i = m - 1; i >= 0; i--) {
            if(b[i] == '1') u++;
            ones[i] = u;
        }

        // for(i = )
        // for(i = 0; i < m; i++) cout << i << " " << ones[i] << endl;

        reverse(a.begin(), a.end());

        for(i = 0; i < n; i++) {
            // cout << i << " " << a[i] << " " << ones[i] << " " << px << endl;

            if(a[i] == '1')
                ans = (ans + (ones[i] * px) % mod) % mod;
            px = (px * 2) % mod;
        }

        cout << ans << endl;
        return 0;   
	}