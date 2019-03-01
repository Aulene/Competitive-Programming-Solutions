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

const int N = 100007;

vvi bruh(N);

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

		cin >> n;

		for(i = 1; i <= 2 * n; i++) {
			cin >> u;
			bruh[u].pb(i);
		}

		for(i = 1; i <= n; i++) sort(bruh[i].begin(), bruh[i].end());

		int p1 = 1, p2 = 1, ans = 0;

		for(i = 1; i <= n; i++) {
			ans += abs(bruh[i][0] - p1) + abs(bruh[i][1] - p2);
			p1 = bruh[i][0];
			p2 = bruh[i][1];
		}

		cout << ans << endl;

		return 0;
	}