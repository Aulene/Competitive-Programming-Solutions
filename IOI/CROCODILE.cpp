#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
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

const int N = 100007;
vector < vector < pair <int, int> > > g(N);
int dist1[N], dist2[N], good[N];

priority_queue < pair <int, int>, vector < pair <int, int> >, greater < pair <int, int> > > pq;

int dijkstra(int n) {

    int ans = INT_MAX;

    for(int i = 1; i <= n; i++)
        if(good[i]) pq.p({i, 0});

    while(!pq.empty()) {

        pi pz = pq.top();
        pq.pop();

        int u = pz.f, v = pz.s;

        if(dist1[u] >= v) {
                dist2[u] = dist1[u];
                dist1[u] = v;
            }
        else if(dist2[u] > v) dist2[u] = v;
        else continue;
        
        cout << "C1 " << u << " " << v << " " << dist1[u] << " " << dist2[u] << endl;

        // if(good[u]) continue;

        cout << "C2 " << u << " " << v << " " << dist1[u] << " " << dist2[u] << endl;

        for(auto it : g[u]) {

            int idx = it.f, w = it.s;

            int dist = v + w;

            cout << idx << " " << dist << " " << dist2[idx] << endl;
            
            if(dist <= dist2[idx]) {
                pq.p({idx, dist});
            }
        }
    }
    
    /*
    2 1
    3 2
    */

    for(int i = 0; i < n; i++) 
        if(good[i]) ans = min(ans, dist2[i]);
    
    cout << "DIST1[] = "; for(int i = 0; i < n; i++) cout << dist1[i] << " "; cout << endl;
    cout << "DIST2[] = "; for(int i = 0; i < n; i++) cout << dist2[i] << " "; cout << endl;
    
    return ans;
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		
		// ifstream cin ("/Users/Aulene/Downloads/ioi2008tests/typ/typ9b.in");
		// ofstream cout ("/Users/Aulene/Desktop/output.txt");

		// ifstream cin ("input.txt");
		// ofstream cout ("output.txt");
		
        int n, m, k, i, j, u, v, w;

        cin >> n >> m >> k;

        for(i = 0; i < N; i++) dist1[i] = dist2[i] = INT_MAX;

        for(i = 0; i < m; i++) {
            cin >> u >> v >> w;
            g[u].pb({v, w}), g[v].pb({u, w});
        }

        for(i = 0; i < k; i++) {
            cin >> u; good[u] = 1;
        }

        int ans = dijkstra(n);

        cout << ans << endl;

		return 0;
	}