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

priority_queue <pi, vpi, less <pi> > pq;

int fmax(vi v) {
	int ans = 0LL;
	for(auto it : v) ans = max(ans, it);
	return ans;
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
		
		int n, m, i, j, u, v, ans = 0;
	
		cin >> n;

		for(i = 1; i <= n; i++) {
			cin >> m;
			vi vx;
			for(j = 0; j < m; j++) cin >> u, vx.pb(u);
			pq.p({fmax(vx), vx.size()});
		}

		// while(!pq.empty()) {
		// 	cout << pq.top().f << " " << pq.top().s << endl; pq.pop();
		// }

		while(pq.size() > 1) {
			pi pz1 = pq.top(); pq.pop();
			pi pz2 = pq.top(); pq.pop();

			// swap(pz1, pz2);

			// cout << "FUCK" << endl;
			// cout << pz1.f << " " << pz1.s << endl;
			// cout << pz2.f << " " << pz2.s << endl;

 			ans += (pz1.f - pz2.f) * pz2.s;
			pi pz = mp(pz1.f, pz1.s + pz2.s);
			pq.p(pz);
		}

		cout << ans << endl;


		return 0;
	}