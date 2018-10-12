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

int a[100007], ct[100007];

vector < pair <int, int> > vs;

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		
		// ifstream cin ("/Users/Aulene/Desktop/input.txt");
		// ofstream cout ("/Users/Aulene/Desktop/output.txt");

		// ifstream cin ("input.txt");
		// ofstream cout ("output.txt");
		
		int n, m, i, j, u, v, ansx = 0, ans = -1;

		cin >> n;

		for(i = 0; i < n - 1; i++) {
			cin >> u >> v;
			vs.pb({u, v});
		}	

		for(i = 1; i <= n; i++) cin >> a[i];

		for(i = 0; i < vs.size(); i++) {
			u = vs[i].f, v = vs[i].s;
			if(a[u] != a[v]) {
				ct[u]++, ct[v]++;
			}
		}

		// for(i = 1; i <= n; i++) cout << ct[i] << " "; cout << endl;

		for(i = 1; i <= n; i++) {
			if(ct[i] > 1) {
				if(ans != -1) ans = 0;
				else ans = i;
			}
		}

		if(ans == -1) ans = 1;

		if(ans) cout << "YES" << endl << ans << endl;
		else cout << "NO" << endl;
		
		return 0;
	}