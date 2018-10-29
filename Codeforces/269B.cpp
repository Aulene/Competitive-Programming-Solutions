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

vi vs;
multiset <int> sx;

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		
		// ifstream cin ("/Users/Aulene/Desktop/input.txt");
		// ofstream cout ("/Users/Aulene/Desktop/output.txt");

		// ifstream cin ("input.txt");
		// ofstream cout ("output.txt");
		
		int n, m, i, j, u;
		double v;

		cin >> n >> m;

		for(i = 1; i <= n; i++) {
			cin >> u >> v;
			vs.pb(u);
		}	

		for(i = 0; i < n; i++) {
			sx.insert(vs[i]);
			auto it = sx.upper_bound(vs[i]);
			if(it != sx.end()) sx.erase(it);
		}

		cout << n - sx.size() << endl;

		return 0;
	}