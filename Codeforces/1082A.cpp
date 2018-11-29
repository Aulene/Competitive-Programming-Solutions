#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define vi vector <int> 
#define vvi vector < vector <int> > 
#define pi pair <int, int> 
#define ppi pair < pair <int, int>, int> 
#define zp mp(0, 0)

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		
		// ifstream cin ("/Users/Aulene/Desktop/input.txt");
		// ofstream cout ("/Users/Aulene/Desktop/output.txt");

		// ifstream cin ("input.txt");
		// ofstream cout ("output.txt");
		
		int t, n, m, i, j, u, v, x, y, d;

		cin	>> t;

		while(t--) {
			cin >> n >> x >> y >> d;

			int ans = LLONG_MAX;

			u = abs(y - x);
			if(u % d == 0) {
				// cout << "oh1 " << u << " " << v << endl;
				ans = min(ans, u / d);
			}

			u = abs(n - y);
			v = abs(n - x);
			if(u % d == 0) {
				// cout << "oh2 " << u << " " << v << endl;
				ans = min(ans, u/d + ((int)ceil((long double)v/d)));
			}

			u = abs(y - 1);
			v = abs(x - 1);

			if(u % d == 0) {
				// cout << "oh3 " << u << " " << v << endl;
				ans = min(ans, u/d + ((int)ceil((long double)v/d)));
			}

			if(ans != LLONG_MAX) cout << ans << endl;
			else 
			cout << -1 << endl;
		}
		return 0;
	}