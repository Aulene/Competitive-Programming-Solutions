#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

int d[100007], a[100007];
int dx[100007], ax[100007];
vector < pair <int, int> > vs;

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, i, j, u, v;

		cin >> n;

		for(i = 0; i < n; i++)
			cin >> d[i] >> a[i], vs.pb(mp(d[i], a[i]));

		
		return 0;
	}