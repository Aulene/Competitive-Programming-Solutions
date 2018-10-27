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

const int N = 200007;

int a[N], p[N], pre[N];
pi pv[N];

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		
		// ifstream cin ("/Users/Aulene/Desktop/input.txt");
		// ofstream cout ("/Users/Aulene/Desktop/output.txt");

		// ifstream cin ("input.txt");
		// ofstream cout ("output.txt");
		
		int n, m, i, j, u, v;
		pair <pi, pi> ansp = mp(mp(0, 0), mp(0, 0));

		cin >> n >> m;

		for(i = 1; i <= n; i++) cin >> a[i];
		for(i = 1; i <= n; i++) pre[i] = pre[i - 1] + a[i];
		for(i = 1; i <= n; i++) if(i + m - 1 <= n) p[i] = pre[i + m - 1] - pre[i - 1];

		// for(i = 1; i <= n; i++) cout << p[i] << " "; cout << endl;

		pv[n + 1] = mp(0, 0);
		for(i = n; i >= 1; i--) {
			if(p[i] >= pv[i + 1].f) pv[i] = mp(p[i], i);
			else pv[i] = pv[i + 1];
		}

		// for(i = 1; i <= n; i++) cout << pv[i].f << " " << pv[i].s << endl;

		for(i = 1; i <= n; i++) {
			if(i + m <= n) {
				if(p[i] + pv[i + m].f > ansp.f.f + ansp.s.f) 
					ansp = mp(mp(p[i], i), pv[i + m]); 
			}
		}

		// cout << ansp.f.f << " " << ansp.s.f << endl;

		cout << ansp.f.s << " " << ansp.s.s << endl;

		return 0;
	}