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

struct layer {
	int l, r;
	ld f;
};

vector <layer> vs;

bool cmp(layer a, layer b) { return a.r < b.r; }

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
		
		int x, y, n, m, i, j, u, v;
		layer l;
		ld neg = 1.0;

		cin >> x >> y >> n;

		if(x < 0) {
			neg = -1.0;
			x = abs(x);
		}

		for(i = 0; i < n; i++) {
			cin >> l.l >> l.r >> l.f;
			vs.pb(l);
		}	

		if(n == 0) {
			l.l = 0; l.r = y;
			l.f = 1.0; vs.pb(l);
		}

		sort(vs.begin(), vs.end(), cmp);

		for(i = 1; i < n; i++) {
			if(vs[i].l > vs[i - 1].r) {
				l.l = vs[i - 1].r; l.r = vs[i].l;
				l.f = 1.0; vs.pb(l);
			}
		}

		// for(auto it : vs) cout << it.l << " " << it.r << " " << it.f << endl;
		// cout << endl;

		if(vs[0].l > 0) {
			l.l = 0; l.r = vs[0].l;
			l.f = 1.0; vs.pb(l);
		}

		sort(vs.begin(), vs.end(), cmp);

		n = vs.size();
		if(vs[n - 1].r < y) {
			l.l = vs[n - 1].r; l.r = y;
			l.f = 1.0; vs.pb(l);
		}
		else if(vs[n - 1].r > y) vs[n - 1].r = y;

		sort(vs.begin(), vs.end(), cmp);

		// for(auto it : vs) cout << it.l << " " << it.r << " " << it.f << endl;

		ld coeff = 0.0;

		for(auto it : vs) {
			ld cur = (ld) (it.r - it.l) * it.f;
			coeff = (ld) cur + coeff;
		}

		ld ans = (ld) x / coeff * neg;
		cout << fixed << setprecision(16) << ans << endl;
		return 0;
	}