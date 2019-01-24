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
#define mid (start + end) / 2

const int N = 307;

int a[N], b[N];
vpi rs;

void upd(int a[], int u, int v, int x) 
	{ for(int i = u; i <= v; i++) a[i] += x; }

int fmax(int a[], int n) {
	int ans = LLONG_MIN;
	for(int i = 1; i <= n; i++) ans = max(ans, a[i]);
	return ans;
}

int fmin(int a[], int n) {
	int ans = LLONG_MAX;
	for(int i = 1; i <= n; i++) ans = min(ans, a[i]);
	return ans;
}

void copy(int a[], int b[], int n) 
	{ for(int i = 1; i <= n; i++) a[i] = b[i]; }

int anscomp(int a[], int n) 
	{ return fmax(a, n) - fmin(a, n); }

bool intersect(int x1, int y1, int x2, int y2) {
	if(x2 <= x1 && x1 <= y2) return 0;
	if(x2 <= y1 && y1 <= y2) return 0;
	if(x1 <= x2 && x2 <= y1) return 0;
	if(x1 <= y2 && y2 <= y1) return 0;
	return 1;	
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
		
		int n, m, i, j, k, u, v, ans = LLONG_MAX;
		vi ansv;

		cin >> n >> m;

		for(i = 1; i <= n; i++) cin >> b[i];

		copy(a, b, n);

		for(i = 0; i < m; i++) {
			cin >> u >> v;
			rs.pb({u, v});
		}

		ans = fmax(a, n) - fmin(a, n);

		for(i = 1; i <= n; i++) {
			
			copy(a, b, n);
			vi av;

			for(j = 0; j < m; j++) {
				
				u = rs[j].f, v = rs[j].s;

				if(!intersect(i, i, u, v)) {
					upd(a, u, v, -1);
					av.pb(j + 1);
				}
			}

			if(ans < anscomp(a, n)) {
				ans = anscomp(a, n);
				ansv = av;
			}
		}

		cout << ans << endl;
		cout << ansv.size() << endl;
		for(auto it : ansv) cout << it << " "; cout << endl;

		return 0;
	}