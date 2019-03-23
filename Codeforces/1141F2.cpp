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

const int N = 1507;
int a[N], pre[N];
map <int, vpi> mx;
vpi ansv;

bool cmp(pi a, pi b) {
	if(a.s != b.s) return a.s < b.s;
	return a.f < b.f;
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

		for(i = 1; i <= n; i++) cin >> a[i], pre[i] = pre[i - 1] + a[i];

		for(i = 1; i <= n; i++)
			for(j = i; j <= n; j++) mx[pre[j] - pre[i - 1]].pb({i, j});

		for(auto it : mx)
			sort(mx[it.f].begin(), mx[it.f].end(), cmp);

		for(auto it : mx) {
			vpi pos_ans;
			int lst = 0;

			for(auto it2 : it.s) {
				int l = it2.f, r = it2.s;
				if(l > lst) {
					pos_ans.pb(it2);
					lst = r;
				}
			}

			if(pos_ans.size() > ansv.size()) 
				ansv = pos_ans;
		}

		cout << ansv.size() << endl;
		for(auto it : ansv) cout << it.f << " " << it.s << endl;
		return 0;
	}