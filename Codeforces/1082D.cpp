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
#define ppi pair < pair <int, int>, int> 
#define zp mp(0, 0)

const int N = 507;

int a[N], deg[N], p[N];
vpi vs, ansv;
vvi g(N);

bool cmp(pi a, pi b) { return a.s > b.s; }

bool vis[N];
int dist[N];
queue<int> q;
int ansx = 1;

int findUp(int idx) {
	int ans = idx;
	while(true) {
		if(deg[idx] < a[idx]) return idx;
		idx = p[idx];
	}
	ansx = 0;
	return 0;
}

int findAnc(int idx) {
	int ans = idx;
	while(idx != 0 && deg[idx] <= a[idx]) {
		// cout << idx << " " << p[idx] << endl;
 		if(deg[idx] < a[idx]) ans = idx;
		idx = p[idx];
	}
	return ans;
}
int bfs(int start)
{
    int i, v;
	
	for(i = 0; i < N; i++) 
		vis[i] = dist[i] = 0;

    vis[start]=1;
    q.push(start);
 
    while(!q.empty())
        {
            v=q.front();
            q.pop();
 
            for(i=0; i < g[v].size(); i++)
                if(!vis[g[v][i]])
                    {
                        vis[g[v][i]]=1;
                        dist[g[v][i]]=dist[v]+1;
                        q.push(g[v][i]);
                    }
        }
 
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
		
		int n, m, i, j, u, v, con = 0, oof;

		cin >> n;

		for(i = 1; i <= n; i++) {
			cin >> a[i];
			vs.pb({i, a[i]});
		}

		sort(vs.begin(), vs.end(), cmp);

		int r = 1;
		con = vs[0].f;

		for(i = 1; i < n; i++) {

			u = vs[i].f, v = vs[i].s;

			if(a[u] == 1) {

				if(i == n - 1 && deg[con] < a[con]) {
					// cout << "1 1 " << u << " " << con << endl;
					
					p[u] = con;
					deg[u]++, deg[con]++;
					g[u].pb(con), g[con].pb(u);
					ansv.pb({u, con});
					con = u;
				}
				else {

					int idx = findAnc(con);
					
					// cout << "1 2 " << u << " con = " << con << " anc = " << idx << endl;
					
					p[u] = idx;
					deg[u]++, deg[idx]++;
					g[u].pb(idx), g[idx].pb(u);
					ansv.pb({u, idx});
				}
			}
			else {
				if(deg[con] < a[con]) {
					// cout << "2 1 " << u << " " << con << endl;

					p[u] = con;
					deg[u]++, deg[con]++;
					g[u].pb(con), g[con].pb(u);
					ansv.pb({u, con});
					con = u;
				}
				else {
					con = findUp(con);

					// cout << "2 2 " << u << " " << con << endl;

					p[u] = con;
					deg[u]++, deg[con]++;
					g[u].pb(con), g[con].pb(u);
					ansv.pb({u, con});
					con = u;
				}
			}
		}

		for(i = 1; i <= n; i++) 
			if(deg[i] == 0 || deg[i] > a[i]) ansx = 0;

		// for(i = 1; i <= n; i++) cout << deg[i] << " "; cout << endl;
		// cout << ansx << endl;
		// for(auto it : ansv) cout << it.f << " " << it.s << endl;
		// cout << endl;

		bfs(1);
 
	    int nodeDis=0, maxDis=0, maxNode;
	    for(j = 1; j<=n; j++)
	        {
	            nodeDis=dist[j];
	            if(nodeDis>maxDis)
	                {
	                    maxDis=nodeDis;
	                    maxNode=j;
	                }
	        }
	 
	    bfs(maxNode);
	 
	    maxDis=0;
	    for(j = 1; j <= n; j++)
	        maxDis = max(dist[j], maxDis);
	 
	    // cout << maxDis << endl;

	    if(!ansx) { cout << "NO" << endl; }
	    else {
	    	cout << "YES " << maxDis << endl;
	    	cout << ansv.size() << endl;
	    	for(auto it : ansv) cout << it.f << " " << it.s << endl;
	    }
		return 0;
	}