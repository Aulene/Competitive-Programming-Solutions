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
#define vpi vector < pair <int, int> >
#define pi pair <int, int> 
#define ppi pair < pair <int, int>, int> 
#define zp mp(0, 0)

vpi vs;

bool cmp(pi a, pi b) {
	if(a.f != b.f) return a.f < b.f;
	return a.s < b.s;
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
		
		int n, x, y, i, j, u, v, ans = 0;
		int store = 0;

		cin >> n >> x >> y;

		for(i = 0; i < n; i++) {
			cin >> u >> v;
			vs.pb({u, v});
		}

		sort(vs.begin(), vs.end(), cmp);

		cout << endl;
		for(auto it : vs) cout << it.f << " " << it.s << endl;
		cout << endl;

		u = 0, v = 0;

		while(u < n && v < n) {

			while(vs[u].f > vs[v].s && v < u) {
				j = (vs[v].s - vs[v].f) % mod;
				j = (j * y) % mod;
				ans = (ans + j) % mod;

				cout << endl;
				cout << "CLOSING " << v << endl;
				cout << "ADDED = " << j << endl;
				cout << "ANS = " << ans << endl;
				cout << "STORE = " << store << endl;
				cout << endl;

				v++, store++;
			}

			if(store) {
				cout << "OPENING " << u << endl;
				store--;
				u++;
			}
			else {
				if(u < n) {
					ans = (ans + x) % mod;
					cout << endl;
					cout << "OPENING " << u << endl;
					cout << "ADDED = " << x << endl;
					cout << "ANS = " << ans << endl;
					cout << endl;
				}
				u++;
			}
		}

		while(v < n) {
			j = (vs[v].s - vs[v].f) % mod;
			j = (j * y) % mod;
			ans = (ans + j) % mod;
			v++;

			cout << endl;
			cout << "CLOSING " << v << endl;
			cout << "ADDED = " << j << endl;
			cout << "ANS = " << ans << endl;
			cout << "STORE = " << store << endl;
			cout << endl;
		}

		cout << ans << endl;
		return 0;
	}