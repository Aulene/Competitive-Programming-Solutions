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

const int N = 100007;

vvi g(N);
int sv[N], av[N];
int ansx = 1;
int ans = 0;

void dfs(int idx, int p = -1, int d = 1) {
	if(p != -1) {

		if(sv[idx] == -1) {
			int val = LLONG_MAX;

			for(auto it : g[idx])
				if(it != p) val = min(val, sv[it]);

			if(val == LLONG_MAX) val = sv[p];
			sv[idx] = val;
		}

		if(sv[idx] < sv[p]) ansx = 0;
		av[idx] = sv[idx] - sv[p];
	}

	for(auto it : g[idx]) 
		if(it != p) dfs(it, idx);
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
		
		int n, m, i, j, u, v;

		cin >> n;

		for(i = 2; i <= n; i++) {
			cin >> u;
			g[u].pb(i), g[i].pb(u);
		}

		for(i = 1; i <= n; i++) cin >> sv[i];
		av[1] = sv[1];

		dfs(1);

		// for(i = 1; i <= n; i++) cout << av[i] << " "; cout << endl;
		// for(i = 1; i <= n; i++) cout << sv[i] << " "; cout << endl;
		for(i = 1; i <= n; i++) ans += av[i];

		if(!ansx) ans = -1;

		cout << ans << endl;

		return 0;
	}