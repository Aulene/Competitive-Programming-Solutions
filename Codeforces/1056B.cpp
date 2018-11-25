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
#define vpi vector < pair <int, int> >
#define vvi vector < vector <int> > 
#define pi pair <int, int> 
#define ppi pair < pair <int, int>, int> 
#define zp mp(0, 0)

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
		vpi vs;

		cin >> n >> m;

		for(i = 1; i <= m; i++)
			for(j = 1; j <= m; j++)
				if((i * i + j * j) % m == 0) vs.pb({i, j});

		for(i = 0; i < vs.size(); i++)
			if(n - vs[i].f >= 0 && (n - vs[i].s >= 0)) {
				u = ((n - vs[i].f) / m) + 1;
				v = ((n - vs[i].s) / m) + 1;
				ans += u * v;
			}

		cout << ans << endl;
		return 0;
	}