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
#define vpi vector < pi >
#define vvpi vector < vector < pi > >
#define ppi pair < pair <int, int>, int> 
#define zp mp(0, 0)

const int N = 50007;

vvpi g(N);
priority_queue < pi, vpi, greater <pi> > pq;

int sp[N];

void dijkstraFx(int n, int sp[]) {

	int dist[N];
	for(int i = 0; i < N; i++) dist[i] = INT_MAX;

	dist[n] = 0;
	pq.p({n, dist[n]});

	while(!pq.empty()) {
		pi pz = pq.top(); pq.pop();

		int u = pz.f, dx = pz.s;

		for(auto it : g[u]) {

			int v = it.f, w = it.s;

			if(dist[v] > dx + w) {
				dist[v] = dx + w;
				pq.p({v, dist[v]}); 
			}
		}
	}

	for(int i = 1; i <= n; i++) sp[i] = dist[i];
	for(int i = 1; i <= n; i++) cout << sp[i] << " "; cout << endl;
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
		
		int n, m, k, i, j, u, v, w;

		cin >> n >> m >> k;

		for(i = 0; i < m; i++) {
			cin >> u >> v >> w;
			g[u].pb({v, w}); g[v].pb({u, w});
		}

		// for(i = 0; i < k; i++) {
		// 	cin >> u >> v;
		// }
		
		dijkstraFx(n, sp);

		return 0;
	}