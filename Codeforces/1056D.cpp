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

const int N = 100007;

vvi g(N);
bool p[N];
int ans[N];
vi vs;

int dfs(int idx, int px = -1) {
	if(p[idx]) return ans[idx];

	int ansx = 0;

	for(auto it : g[idx])
		if(it != px) ansx += dfs(it, idx);

	return ans[idx] = ansx;
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
		
		int n, m, i, j, u, v;

		for(i = 0; i < N; i++) p[i] = 1;

		cin >> n;

		for(i = 2; i <= n; i++) {
			cin >> u;
			g[u].pb(i);
			g[i].pb(u);
			p[u] = 0;
		}

		for(i = 1; i <= n; i++)
			if(p[i]) ans[i] = 1;

		dfs(1);

		for(i = 1; i <= n; i++) vs.pb(ans[i]);
		sort(vs.begin(), vs.end());
		for(auto it : vs) cout << it << " "; cout << endl;
		return 0;
	}