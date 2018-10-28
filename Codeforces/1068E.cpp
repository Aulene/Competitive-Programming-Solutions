#include <bits/stdc++.h>
#include <unordered_map>

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
#define mid (start + end) / 2
#define pi pair <int, int>
#define N 100007

vvi g(N);
bool ansx = 1;

int dfs(int idx, int lvl) {


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
		
        int n, m, i, j, u, v;
        int root = -1;

        cin >> n >> m;

        for(i = 0; i < n - 1; i++) {
            cin >> u >> v;
            g[u].pb(v), g[v].pb(u);
        }

        for(i = 1; i <= n; i++) {
            if(g[i].size() == 3) {
                if(root == -1) root = i;
                else ansx = 0;
            }
        }

        if(!ansx) {
            cout << "No\n"; return 0;
        }

        dfs(root, m);

		return 0;
	}