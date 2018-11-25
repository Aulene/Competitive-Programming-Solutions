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

vvi vs(107);
vi ansv;

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		
		// ifstream cin ("/Users/Aulene/Desktop/input.txt");
		// ofstream cout ("/Users/Aulene/Desktop/output.txt");

		// ifstream cin ("input.txt");
		// ofstream cout ("output.txt");
		
		int n, m, i, j, k, u, v, ans = 0;
		bool av;

		cin >> n;

		for(i = 0; i < n; i++) {
			cin >> m;
			for(j = 0; j < m; j++) cin >> u, vs[i].pb(u);
		}

		for(i = 1; i <= 100; i++) {
			int bv = 1;

			for(j = 0; j < n; j++) {

				av = 0;
				for(k = 0; k < vs[j].size(); k++) {
					if(vs[j][k] == i) {
						av = 1;
						break;
					}
				}

				if(!av) {
					bv = 0;
					break;
				}
			}

			if(bv) ansv.pb(i);
		}

		for(i = 0; i < ansv.size(); i++) cout << ansv[i] << " "; cout << endl;
		return 0;
	}