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

const int N = 300007;

int dist(pair <int, int> a, pair <int, int> b) { return abs(a.f - b.f) + abs(a.s - b.s); }

set < pair <int, int> > s;
vector < pair <int, int> > vs;
vi ansv;
int l[N], r[N], cur_sum[N];

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		
		// ifstream cin ("/Users/Aulene/Desktop/input.txt");
		// ofstream cout ("/Users/Aulene/Desktop/output.txt");

		// ifstream cin ("input.txt");
		// ofstream cout ("output.txt");
		
		int n, m, i, j, u, v, sum = 0;

		cin >> n;

		for(i = 0; i < n; i++) {
			cin >> u >> v;
			l[i] = (i - 1 + n) % n;
			r[i] = (i + 1 + n) % n;
			vs.pb({u, v});
		}

		for(i = 0; i < n; i++) {
			int d = dist(vs[i], vs[l[i]]) + dist(vs[i], vs[r[i]]);
			cur_sum[i] = d;
			sum += dist(vs[i], vs[l[i]]);
			s.insert({d, i});
		}

		// cout << sum << endl;

		// for(i = 0; i < n; i++) cout << l[i] << " "; cout << endl;
		// for(i = 0; i < n; i++) cout << r[i] << " "; cout << endl;

		// cout << endl;
		// for(auto it : s) cout << it.f << " " << it.s << endl;
		// cout << endl;

		for(j = n; j >= 3; j--) {
			ansv.pb(sum);

			pair <int, int> pz = *s.begin();
			s.erase(s.begin());

			sum -= pz.f;

			i = pz.s;

			s.erase({cur_sum[l[i]], l[i]});
			s.erase({cur_sum[r[i]], r[i]});
			
			sum += dist(vs[l[i]], vs[r[i]]);

			l[r[i]] = l[i];
			r[l[i]] = r[i];

			cur_sum[l[i]] = dist(vs[l[i]], vs[l[l[i]]]) + dist(vs[l[i]], vs[r[l[i]]]);
			cur_sum[r[i]] = dist(vs[r[i]], vs[l[r[i]]]) + dist(vs[r[i]], vs[r[r[i]]]);

			s.insert({cur_sum[l[i]], l[i]});
			s.insert({cur_sum[r[i]], r[i]});

			// cout << endl;
			// for(auto it : s) cout << it.f << " " << it.s << endl;
		}

		// for(auto it : s) cout << it.f << " " << it.s << endl;

		reverse(ansv.begin(), ansv.end());
		for(auto it : ansv) cout << it << " "; cout << endl;
		return 0;
	}