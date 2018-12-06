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

vvi g(N);
vi ansv;

int n;

int dfs(int idx, int p = -1) {

	if(idx == n) {
		ansv.pb(idx);
		return 1;
	}

	for(auto it : g[idx]) {
		if(it != p) {

			if(dfs(it, idx)) {
				ansv.pb(idx);
				return 1;
			}

		}
	}

	return 0;
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
		
		int m, i, j, u, v;

		cin >> n;

		for(i = 2; i <= n; i++) {
			cin >> u;
			g[u].pb(i), g[i].pb(u);
		}	

		dfs(1);
		reverse(ansv.begin(), ansv.end());

		for(auto it : ansv) cout << it << " "; cout << endl;
		return 0;
	}