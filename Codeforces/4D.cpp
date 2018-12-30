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
#define vpi vector < pi >
#define vppi vector < ppi >
#define vvpi vector < vector < pi > > 
#define zp mp(0, 0)

const int N = 5007;

vppi vs;

int dp[N], par[N], cur[N];

bool cmp(ppi a, ppi b) {
	if(a.f.s != b.f.s) return a.f.s < b.f.s;
	return a.f.f < b.f.f;
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		
		// ifstream cin ("/Users/Aulene/Desktop/input.txt");
		// ofstream cout ("/Users/Aulene/Desktop/output.txt");

		// ifstream cin ("input.txt");
		// ofstream cout ("output.txt");
		
		// ifstream cin ("usaco.in");
		// ofstream cout ("usaco.out");
		
		int n, m, i, j, u, v, r, c;
		int mx = 0, mv = 0;

		cin >> n >> r >> c;

		vs.pb({{r, c}, 0});

		for(i = 1; i <= n; i++) {
			cin >> u >> v;
			if(u > r && v > c) vs.pb({{u, v}, i});
		}

		sort(vs.begin(), vs.end(), cmp);

		n = vs.size();

		if(n == 1) {
			cout << 0 << endl;
			return 0;
		}

		// for(auto it : vs) cout << it.f.f << " " << it.f.s << endl;

		dp[0] = 1;
		par[0] = -1;

		for(i = 1; i < n; i++) {

			cur[i] = vs[i].s;

			for(j = 0; j < i; j++) {

				if(vs[j].f.f < vs[i].f.f && vs[j].f.s < vs[i].f.s) {
					if(dp[i] < 1 + dp[j]) {
						dp[i] = 1 + dp[j];
						par[i] = j;
					}
				}

			}
		}

		// for(i = 0; i < n; i++) cout << dp[i] << " "; cout << endl;

		for(i = 1; i < n; i++)
			if(mx < dp[i]) {
				mx = dp[i];
				mv = i;
			}

		vi ansv;

		while(par[mv] != -1) {
			ansv.pb(cur[mv]);
			mv = par[mv];
		}

		reverse(ansv.begin(), ansv.end());
		
		cout << ansv.size() << endl;
		for(auto it : ansv) cout << it << " "; cout << endl;

		return 0;
	}