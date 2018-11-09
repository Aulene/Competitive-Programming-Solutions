#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define mid (start + end) / 2
#define vvi vector < vector <int> > 
#define pi pair <int, int> 
#define ppi pair < pair <int, int>, int >

const int N = 200007;

vvi g(N);
stack < pair <int, int> > s;
int disc[N], low[N];
int timer = 1;

int dfs(int idx, int p = -1) {

    int children = 0;
    disc[idx] = low[idx] = timer++;

    for(auto it : g[idx]) {
        int v = it;

        if(!disc[v]) {

            children++;
            s.p({idx, v});
            
            dfs(v, idx);
        
            low[idx] = min(low[idx], low[v]);

            if((disc[idx] == 1 && children > 1) || (disc[idx] > 1 && low[v] >= disc[idx])) {

                while(idx != s.top().f  || v != s.top().s) {
                    cout << s.top().f << " -- " << s.top().s << " ";
                    s.pop();
                }

                cout << s.top().f << " -- " << s.top().s;
                s.pop();
                cout << endl;
            }

        }
        else if(v != p) {
            low[idx] = min(low[idx], disc[v]);
            if(disc[v] < disc[idx]) s.p({idx, v});
        }
    }
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
        cout.tie(NULL);

        int n, m, i, j, u, v;

        cin >> n >> m;

        for(i = 0; i < m; i++) {
            cin >> u >> v;
            g[u].pb(v), g[v].pb(u);
        }

        dfs(1);	

        while(!s.empty()) {
            cout << s.top().f << " -- " << s.top().s << " ";
            s.pop();
        } cout << endl;
		return 0;   
	}