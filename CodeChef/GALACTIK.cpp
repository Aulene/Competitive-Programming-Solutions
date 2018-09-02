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

int lk[100007], sz[100007];

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);

		int n, m, i, j, u, v;

		cin >> n >> m;

		for(i = 1; i <= n; i++) lk[i] = i;
		for(i = 1; i <= n; i++) sz[i] = 1;

		for(i = 0; i < m; i++)
			{
				cin >> u >> v;

			}
		return 0;
	}