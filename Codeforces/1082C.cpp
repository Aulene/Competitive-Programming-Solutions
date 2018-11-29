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

const int N = 100007;

vvi vs(N);
int sum[N], psum[N];

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		
		// ifstream cin ("/Users/Aulene/Desktop/input.txt");
		// ofstream cout ("/Users/Aulene/Desktop/output.txt");

		// ifstream cin ("input.txt");
		// ofstream cout ("output.txt");
		
		int n, m, i, j, u, v, ans = 0;

		cin >> n >> m;

		for(i = 0; i < n; i++) {
			cin >> u >> v;
			vs[u].pb(v);
		}

		for(i = 1; i <= m; i++) sort(vs[i].begin(), vs[i].end(), greater <int>());

		// for(i = 1; i <= m; i++) {
		// 	cout << i << ": ";
		// 	for(auto it : vs[i]) cout << it << " "; cout << endl;
		// }
		
		for(i = 1; i <= m; i++) {
			for(j = 0; j < vs[i].size(); j++) {
				psum[i] = psum[i] + vs[i][j];
				if(psum[i] >= 0) 
					sum[j] += psum[i];
			}
		}

		// for(i = 0; i <= n; i++) cout << sum[i] << " "; cout << endl;

		for(i = 0; i <= n; i++) ans = max(ans, sum[i]);

		cout << ans << endl;

		return 0;
	}