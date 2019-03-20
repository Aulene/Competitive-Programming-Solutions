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
#define msi multiset <int> 
#define si set <int>
#define zp mp(0, 0)

#define ld long double

const int N = 1007;

vi src;
vvi g(N);

int in[N], order[N], num_ord[N];
set < pi> dijk_set;

void dijks(int n) {

	for(int i = 1; i <= n; i++)
		dijk_set.insert({in[i], i});

	while(dijk_set.size()) {

		pi pz = *dijk_set.begin();
		dijk_set.erase(dijk_set.begin());

		int idx = pz.s;

		// cout << "src: " << idx << " " << pz.f << " ord: " << order[idx] << endl;

		for(auto it : g[idx]) {
			if(order[it] < order[idx])
				order[it] = order[idx], num_ord[it] = 1;
			else if(order[it] == order[idx]) {
				if(num_ord[it] == 1) order[it]++, num_ord[it] = 0;
				else num_ord[it]++;
			}
			
			dijk_set.erase({in[it], it});
			in[it]--;
			dijk_set.insert({in[it], it});			
		}

		// cout << "curset:\n";
		// for(auto it : dijk_set) 
		// 	cout << "deg: " << it.f << " idx: " << it.s << " ord: " << order[it.s] << endl;
		// cout << "end curset\n";
	}
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
		
		int n, m, i, j, u, v, t;

		cin >> t;

		for(int T = 1; T <= t; T++) {
			int ans = 0;

			cin >> u >> n >> m;

			src.clear();
			for(i = 0; i < N; i++) {
				g[i].clear();
				in[i] = 0; order[i] = 0; num_ord[i] = 0;
			}

			for(i = 0; i < m; i++) {
				cin >> u >> v;
				g[u].pb(v);
				in[v]++;
			}

			for(i = 1; i <= n; i++)
				if(in[i] == 0) order[i] = 1;
			
			dijks(n);

			for(i = 1; i <= n; i++) {
				// cout << order[i] << " ";
				ans = max(ans, order[i]);
			}

			// cout << endl;
			cout << T << " " << ans << endl;
		}

		return 0;
	}