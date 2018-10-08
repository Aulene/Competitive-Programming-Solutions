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

int a[507];
unordered_map <int, int> mx;
set <int> sx;

int peeness(int x)
{
    int u = sqrt(x);
    
    if(u * u == x) {

        int v = sqrt(u);
        if(v * v == u) {
            return 4;
        }

        return 2;
    }
    else {
        int v = cbrt(x);

        if(v * v * v == x) {
            return 3;
        }
    }

    return 0;
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, m, q, u, v, i, j, x, y, ans = 1;
        
        cin >> n;

        for(i = 0; i < n; i++) cin >> a[i];

        for(i = 0; i < n; i++)
            {
                for(j = i + 1; j < n; j++)
                    {
                        x = __gcd(a[i], a[j]);
                        y = peeness(x);

                        if(sx.count(x) == 0) sx.insert(x);

                        a[i] /= x;
                        a[j] /= x;
                        mx[x] += y;
                    }
            }

        for(set <int> :: iterator it = sx.begin(); it != sx.end(); it++) {
            u = *it;
            ans = (ans * (mx[u] + 1)) % mod;
            cout << "DP[" << u << "] = " << mx[u] + 1 << endl;
        }

        for(i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
        cout << ans << endl;

		return 0;
	}