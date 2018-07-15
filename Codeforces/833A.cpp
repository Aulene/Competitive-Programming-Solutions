#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

int MAXR = 1000007;

int cubic_root(int x)
{
    int l = 0, r = MAXR;
    while (l != r) {
        int m = (l + r + 1) / 2;
        if (m * m * m > x)
            r = m - 1;
        else
            l = m;
    }
    return l;
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int t, n, a, b, u, s;

		cin >> t;

		while(t--) 
			{
				cin >> a >> b;
				s = a * b;

				u = cubic_root(s);
				// cout << u << endl;

				int v = u * u * u;
				
				if(v == s && (a % u == 0) && (b % u == 0)) cout << "Yes\n";
				else cout << "No\n";
			}


		return 0;
	}