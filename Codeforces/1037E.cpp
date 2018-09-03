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

int sz[200007];
int frd[200007];

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);

		int n, m, k, i, j, u, v, ans = 0;

		cin >> n >> m >> k;

		for(i = 0; i < m; i++)
			{
				cin >> u >> v;
				sz[u]++, sz[v]++;

				if(frd[u] == k) 
				if(sz[u] == k) ans++;
				if(sz[v] == k) ans++;

				cout << ans << endl;
			}
		return 0;
	}