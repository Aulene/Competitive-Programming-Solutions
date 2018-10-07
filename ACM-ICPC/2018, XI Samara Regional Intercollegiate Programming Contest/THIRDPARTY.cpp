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

vector < pair <int, int> > vs;

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		
		// ifstream cin ("/Users/Aulene/Desktop/input.txt");
		// ofstream cout ("/Users/Aulene/Desktop/output.txt");

		// ifstream cin ("input.txt");
		// ofstream cout ("output.txt");
		
		int n, m, i, j, u, v, ans = LLONG_MAX;

		cin >> n;

		for(i = 0; i < n; i++) {
			cin >> u >> v;
			vs.pb({u, v});
		}	

		for(i = 0; i < n; i++) {
			pair <int, int> pz1, pz2, pz3;

			pz1 = vs[i % n];
			pz2 = vs[(i + 1) % n];
			pz3 = vs[(i + 2) % n];

			u = (pz1.f * (pz2.s - pz3.s)) + (pz2.f * (pz3.s - pz1.s)) + (pz3.f * (pz1.s - pz2.s));
			// cout << u << endl;

			u = abs(u);
			ans = min(ans, u);
		}

		cout << ans << endl;

		return 0;
	}