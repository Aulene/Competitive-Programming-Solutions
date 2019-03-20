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

const int N = 2007;
int a[N], b[N];
map <int, int> mx;

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
		int ans, av = 0;

		cin >> n >> m;

		for(i = 1; i <= n; i++) cin >> a[i];
		for(i = 1; i <= m; i++) cin >> b[i];

		for(i = 1; i <= n; i++)
			for(j = 1; j <= m && b[j] >= a[i]; j++) 
				mx[b[j] - a[i]]++;

		for(auto it : mx)
			if(it.s > av || (it.s == av && ans > it.f)) {
				av = it.s;
				ans = it.f;
			}

		cout << ans << endl;

		return 0;
	}