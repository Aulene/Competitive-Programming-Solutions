#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

int a[100007];
vector < pair <int, int> > incv, decv;

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, k, i, j, u, v, ans = 0, mv;
		int l = 0, r = 0;
		int ansinc = 0, ansdec = 0;
		int incbef, incaf, decbef, decaf;

		cin >> n >> k;

		for(i = 1; i <= n; i++) cin >> a[i];
		
		for(i = 1; i <= n; i++)
			{
				u = i;
				while(a[i + 1] >= a[i] && i <= n) i++;
				incv.pb(mp(u, i));	
			}

		for(i = 1; i <= n; i++)
			{
				u = i;
				while(a[i + 1] <= a[i] && i + 1 <= n) i++;
				decv.pb(mp(u, i));
			}
 
		for(i = 0; i < incv.size(); i++) cout << incv[i].f << " " << incv[i].s << endl;
		for(i = 0; i < decv.size(); i++) cout << decv[i].f << " " << decv[i].s << endl;

		incbef = 0, incaf = 0;

		while()

		return 0;
	}
