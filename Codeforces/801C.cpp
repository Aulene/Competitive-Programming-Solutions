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
#define ld long double
#define pd pair <pi, ld>

vector < pair <ld, ld> > vs;

class ComparisonClass {
    bool operator() (pd a, pd b) {
    	return a.s < b.s;
    }
};

bool cmp(pi a, pi b) { return a.f < b.f; }
bool cmp2(pair <pi, ld> a, pair <pi, ld> b) { return a.s < b.s; }

bool check(ld time, int p) {
	ld sum = 0;

	for(auto it : vs) {
		ld tdeath = (ld) max((ld) 0 * 1.0, time * it.f - it.s);
		sum += tdeath;
	}

	sum = (ld) (sum / time);
	if(sum <= p) return 1;
	return 0;
}

ld bsearch(int p) {

	ld low = 0.0, mid, high = 1e14, ans;

	while(low <= high) {
		mid = (low + high) / 2;

		if(check(mid, p)) {
			ans = mid;
			low = mid + 0.00001;
		}
		else high = mid - 0.00001;
	}

	return ans;
}

// void compute(int p) {
// 	priority_queue <pd, vector <pd>, greater <pd> > pq;
// 	ld tm = 0;

// 	for(int i = 0; i < vs.size(); i++) {
// 		ld tdeath = vs[i].s / vs[i].f;
// 		pq.p({vs[i], tdeath});
// 	}

// 	while(!pq.empty()) {
// 		pd fx = pq.top(); pq.pop();

// 		if(fx.s <= tm) break;

// 		pd nx = pq.top();

// 		ld t1 = fx.s, t2 = nx.s, t = (ld) t2 - t1;



// 		cout << fixed << setprecision(10) << fx.f.f << " " << fx.f.s << " " << fx.s << endl;
// 	}
// }

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
		
		int n, m, i, j, sum = 0;
		ld u, v;
		int ansx = 1;

		cin >> n >> m;

		for(i = 0; i < n; i++) {
			cin >> u >> v;
			sum += u;
			vs.pb({u, v});
		}

		sort(vs.begin(), vs.end(), cmp);

		if(sum <= m) ansx = 0;

		if(!ansx) {
			cout << -1 << endl;
			return 0;
		}

		ld ans = bsearch(m);	
		cout << fixed << setprecision(10) << ans << endl;

		return 0;
	}