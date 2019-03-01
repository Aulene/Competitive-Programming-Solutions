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
#define vpi vector < pi >
#define vppi vector < ppi >
#define vvpi vector < vector < pi > > 
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
		
		// ifstream cin ("usaco.in");
		// ofstream cout ("usaco.out");
		
		int t, n, i, j, u, v;

		cin >> t;

		for(int T = 1; T <= t; T++) {
			cin >> n;
			
			vi ansv;

			int N = n;
			while(n) {
				ansv.pb(n % 10);
				n /= 10;
			}
			reverse(ansv.begin(), ansv.end());
			n = N / 10;
			while(n) {
				ansv.pb(n % 10);
				n /= 10;
			}
			cout << "Case " << T << ": "; 
			for(auto it: ansv) cout << it; cout << endl; 
		}	
		return 0;
	}