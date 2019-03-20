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

const int N = 507;
int a[N][N], b[N][N];
vector < msi > mx1(2 * N + 7), mx2(2 * N + 7);

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
		
		int n, m, i, j, u, v;

		cin >> n >> m;

		for(i = 1; i <= n; i++) 
			for(j = 1; j <= m; j++) cin >> a[i][j], mx1[i + j].insert(a[i][j]);	
		for(i = 1; i <= n; i++) 
			for(j = 1; j <= m; j++) cin >> b[i][j], mx2[i + j].insert(b[i][j]);	

		int ans = 1;

		for(i = 0; i <= 2 * N; i++)
			if(mx1[i] != mx2[i]) ans = 0;

		if(ans) cout << "YES" << endl;
		else cout << "NO" << endl; 
		return 0;
	}