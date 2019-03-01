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
		
		int t, n, d, x, i, j, u, v;

		cin >> t;
		for(int T = 1; T <= t; T++) {
			cin >> d >> x;
			int sum = 0;
			while(d >= 0) {
				sum += pow(2, d);
				d--;
			}
			cout << "Case " << T << ": ";
			if(sum < x) cout << "NO\n";
			else cout << "YES " << sum -( pow(2, d + 1) - 1) << endl;;
		}	
		return 0;
	}