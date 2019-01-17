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

const int N = 200007;
int a[N], b[N], pre[N];
vpi vs;

bool cmp(pi a, pi b) {
	return a.s - a.f > b.s - b.f;
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

		cin >> n >> m;
		for(i = 1; i <= n; i++) cin >> a[i];
		for(i = 1; i <= n; i++) cin >> b[i];
		for(i = 1; i <= n; i++) vs.pb({a[i], b[i]});

		sort(vs.begin(), vs.end(), cmp);

		// for(auto it : vs) cout << it.f << " " << it.s << " " << it.s - it.f << endl;

		pre[0] = vs[0].s;
		for(i = 1; i < n; i++) pre[i] = pre[i - 1] + vs[i].s;

		int sum = 0, ans = LLONG_MAX;

		for(i = 0; i < m; i++) sum += vs[i].f;

		ans = min(ans, sum + pre[n - 1] - pre[m - 1]);
		// cout << ans << endl;

		for(i = m; i < n; i++) {
			sum += vs[i].f;
			// cout << i << " " << ans << " " << sum << " " << pre[n - 1] - pre[i - 1] << endl;
			ans = min(ans, sum + pre[n - 1] - pre[i]);
		}

		cout << ans << endl;
	
		return 0;
	}