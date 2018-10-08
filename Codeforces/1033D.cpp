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
                int v = peeness(a[i]);

                cout << i << " " << v << endl;
                if(v != 0) {
                    if(v == 4) u = sqrt(sqrt(a[i]));
                    else if(v == 3) u = cbrt(a[i]);
                    else if(v == 2) u = sqrt(a[i]);

                    mx[u] += v;
                    if(sx.count(u) == 0) sx.insert(u);
                    a[i] = 1;
                }
            }

        for(i = 0; i < n; i++) {
            for(j = i + 1; j < n; j++) {
                u = __gcd(a[i], a[j]);

                a[i] /= u;
                a[j] /= u;
                mx[u] += 2;
            }
        }

        for(i = 0; i < n; i++) {

        }
        
        for(i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
        cout << ans << endl;

		return 0;
	}