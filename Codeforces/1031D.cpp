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

const int N = 2007;

char a[N][N];
int dp[N][N];
vector < pair < pair <int, int>, char> > vs;

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
		pair < pair <int, int>, char> pz, np;
		string ans = "";

		cin >> n >> m;

		u = 0;

		for(i = 1; i <= n; i++)
			for(j = 1; j <= n; j++) cin >> a[i][j];

		dp[1][1] = (a[1][1] == 'a') ? 0 : 1; 

		for(i = 1; i <= n; i++) {
			for(j = 1; j <= n; j++) {

				if(i == 1 && j == 1) continue;

				int fadd = INT_MAX;
				if(j - 1 > 0) fadd = min(fadd, dp[i][j - 1]);
				if(i - 1 > 0) fadd = min(fadd, dp[i - 1][j]);
				if(a[i][j] != 'a') fadd += 1;
				
				dp[i][j] = fadd;
			}
		}

		// for(i = 1; i <= n; i++) {
		// 	for(j = 1; j <= n; j++) cout << dp[i][j] << " "; cout << endl;
		// }

		for(i = 1; i <= n; i++) {
			for(j = 1; j <= n; j++) {
				if(dp[i][j] <= m) u = max(i + j - 1, u);
			}
		}

		for(i = 1; i <= n; i++) {
			for(j = 1; j <= n; j++) {
				if(dp[i][j] <= m && (i + j - 1 == u)) {
					if(i + 1 <= n) vs.pb({{i + 1, j}, a[i + 1][j]});
					if(j + 1 <= n) vs.pb({{i, j + 1}, a[i][j + 1]});
				}
			}
		}

		// cout << u << endl;

		// for(auto it : vs) cout << it.f.f << " " << it.f.s << " " << it.s << endl;

		for(i = 0; i < u; i++) ans += 'a';

		char x = (char) 'z' + 1;

		pz = mp(mp(n + 1, n + 1), x);

		for(auto it : vs) { if(it.s < pz.s) { pz = it; } }

		if(pz != mp(mp(n + 1, n + 1), x)) {
			ans += pz.s;
			vs.clear();

			np = mp(mp(pz.f.f + 1, pz.f.s), a[pz.f.f + 1][pz.f.s]);
			if(np.f.f <= n && np.f.s <= n) vs.pb(np);
			np = mp(mp(pz.f.f, pz.f.s + 1), a[pz.f.f][pz.f.s + 1]);
			if(np.f.f <= n && np.f.s <= n) vs.pb(np);
		}

		// for(auto it: vs) {
		// 	cout << it.s << " ";
		// } cout << endl;

		if(m == 0 && a[1][1] != 'a') vs.pb({{1, 1}, a[1][1]});

		while(!vs.empty()) {
			char x = (char) 'z' + 1;

			pz = mp(mp(-1, -1), x);

			for(auto it : vs) {
				if(it.s < pz.s) { pz = it; }
			}

			ans += pz.s;
			vs.clear();

			pair < pair <int, int>, char> np = mp(mp(pz.f.f + 1, pz.f.s), a[pz.f.f + 1][pz.f.s]);
			if(np.f.f <= n && np.f.s <= n) vs.pb(np);
			np = mp(mp(pz.f.f, pz.f.s + 1), a[pz.f.f][pz.f.s + 1]);
			if(np.f.f <= n && np.f.s <= n) vs.pb(np);
		}

		cout << ans << endl;

		return 0;
	}