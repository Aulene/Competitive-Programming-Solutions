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

const int N = 200007;
vi vs, tax, cust;
int ans[N], taxi[N];

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

		cin >> n >> m;

		for(i = 0; i < n + m; i++) cin >> u, vs.pb(u);
		for(i = 0; i < n + m; i++) cin >> taxi[i];

		for(i = 0; i < n + m; i++)
			if(taxi[i]) tax.pb(vs[i]);
			else cust.pb(vs[i]);

		if(m == 1) {
			cout << n << endl;
			return 0;
		}

		j = i = 0;

		while(i < n) {
			if(j < m - 1) {
				
				int dist1 = abs(cust[i] - tax[j]);
				int dist2 = abs(cust[i] - tax[j + 1]);

				if(dist1 < dist2) {
					ans[j]++;
					i++;
				}
				else if(dist1 == dist2) {
					ans[j]++;
					i++;
					j++;
				}
				else if(dist1 > dist2) {
					j++;
				}
			}
			else {
				i++;
				ans[j]++;
			}
		}

		for(i = 0; i < m; i++) cout << ans[i] << " "; cout << endl;
		return 0;
	}