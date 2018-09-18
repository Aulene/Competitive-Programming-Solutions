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

int a[200007], ansv[200007];
set <int> sx;
map <int, int> mx;

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);

		int n, m, d, i, j, u, v, ans = 1;
		set <int> :: iterator it;

		cin >> n >> m >> d;

		for(i = 0; i < n; i++) {
			cin >> u;
			// cin >> u;
			sx.insert(u);
			mx[u] = i;
		}

		while(!sx.empty())
			{
				it = sx.begin();

				while(it != sx.end()) 
					{
						u = *it;
						ansv[mx[u]]= ans;
						sx.erase(u);
						it = sx.upper_bound(u + d);
					}

				ans++;
			}

		cout << ans - 1 << endl;
		// cout << ans - 1 << endl;
		for(i = 0; i < n; i++) cout << ansv[i] << " "; cout << endl;

		return 0;
	}