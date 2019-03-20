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
#define msi multiset <int> 
#define si set <int>
#define zp mp(0, 0)

#define ld long double

const int N = 17;

char g[N][N];
vvi vs(10, vi (10, 0));

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
		
		int n, m, i, j, u, v, q;
		char c;

		cin >> n >> m;

		for(i = 1; i <= n; i++)
			for(j = 1; j <= m; j++) cin >> g[i][j];

		for(i = 1; i <= n; i++)
			for(j = 1; j <= m; j++)
				if(g[i][j] != '-') vs[i][j] = (int) g[i][j] - '0';

		cin >> q;

		while(q--) {
			
		}
		
			
		return 0;
	}