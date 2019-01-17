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

bool cmp(ppi a, ppi b) {
	return a.f.f < b.f.f;
}

const int N = 100007;
int ans[N];

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
		
		int n, m, i, j, u, v, t, rx;

		cin >> t;

		while(t--) {
				
			for(i = 0; i < N; i++) ans[i] = 0;

			cin >> n;

			vppi vs;

			for(i = 1; i <= n; i++) {
				cin >> u >> v;
				vs.pb({{u, v}, i});
			}

			sort(vs.begin(), vs.end(), cmp);

			int l1 = -1, r1 = -1, idx = 0, ansx = 1;
			
			// l1 = vs[0].f.s;
			// ans[vs[0].s] = 1;

			while(idx < n) {

				u = vs[idx].f.f, v = vs[idx].f.s, rx = vs[idx].s;

				// cout << idx << " " << l1 << " " << r1 << endl;
				// cout << u << " " << v << endl;

				if(l1 != -1 && r1 != -1 && u <= l1 && u <= r1) {
					ansx = 0;
					break;
				}

				if(l1 == -1 || u <= l1) {
					ans[rx] = 1;
					l1 = max(l1, v);
				}
				else if(r1 == -1 || u <= r1) {
					ans[rx] = 2;
					r1 = max(r1, v);
				}
				else if(u > l1 && u > r1) {
					ans[rx] = 1;
					l1 = max(l1, v);
				}
				else {
					ansx = 0;
					break;
				}

				idx++;
			}

			if(l1 == -1 || r1 == -1) ansx = 0;
			for(i = 1; i <= n; i++) 
				if(ans[i] == 0) ansx = 0;

			if(!ansx) cout << "-1" << endl;
			else {
				for(i = 1; i <= n; i++) cout << ans[i] << " "; cout << endl;
			}
		}	
		return 0;
	}