#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, m, i, j, u, v, x, y, ans = 1;
		string s1, s2;

		cin >> n >> m >> s1 >> s2;

		u = 0;

		for(i = 0; i < s2.size(); i++) {
			if(s1[u] != '*') {
				if(s1[u] != s2[i]) ans = 0;
				u++;
			}
			else break;
		}
		
		x = i - 1;
		v = u;
		u = s1.size() - 1;

		for(i = s2.size() - 1; i >= 0; i--) {
			// cout << i << " " << u << endl;
			// cout << s2[i] << " " << s1[u] << endl;

			if(s1[u] != '*') {
				if(s1[u] != s2[i]) ans = 0;
				u--;
			}
			else break;
		}

		y = i + 1;
		
		// cout << v << " " << u << endl;
		// cout << x << " " << y << endl;

		if(ans && x <= y) cout << "YES\n";
		else cout << "NO\n";

		return 0;
	}