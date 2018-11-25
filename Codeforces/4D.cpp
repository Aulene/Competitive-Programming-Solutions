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
#define vpi vector < pair <int, int> >
#define vppi vector < pair < pair <int, int>, int > > 
#define vvi vector < vector <int> > 
#define pi pair <int, int> 
#define ppi pair < pair <int, int>, int> 
#define zp mp(0, 0)

const int N = 5007;

pi dp[N][N];
vppi vs;

bool cmp(ppi ax, ppi bx) {
	pi a = ax.f, b = bx.f;
	if(a.f != b.f) return a.f < b.f;
	return a.s < b.s;
}

bool cmp2(pi a, pi b) {
	if(b.f > a.f && b.s > a.s) return 1;
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
		
		int n, m, i, j, u, v, w, h;

		cin >> n >> w >> h;

		for(i = 0; i < N; i++)
			for(j = 0; j < N; j++) dp[i][j] = mp(INT_MIN, -1);

		vs.pb({{w, h}, 0});

		for(i = 0; i < n; i++) {
			cin >> u >> v;
			if(u <= w || v <= h) continue;
			vs.pb({{u, v}, i + 1});
		}

		n = vs.size();
		sort(vs.begin(), vs.end(), cmp);

		dp[0][0] = mp(1, -1);

		for(i = 1; i < n; i++) {
			pi a = vs[i].f;

			for(j = 0; j < i; j++) {
				pi b = vs[j].f;
				if(cmp2(a, b)) dp[i][j] = mp(1 + dp[i - 1][j].f, j);
			}
		}

		for(i = 0; i < n; i++) cout << vs[i].f.f << " " << vs[i].f.s << endl;

		for(i = 0; i < n; i++) {
			for(j = 0; j < n; j++) cout << dp[i][j].f << " "; cout << endl;
		}
		return 0;
	}