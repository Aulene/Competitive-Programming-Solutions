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

const int N = 200007;

int a[N], dpl[N], dpr[N];

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

		cin >> n;

		for(i = 1; i <= n; i++) cin >> a[i];
		dpl[1] = 1; dpr[n] = 1;

		for(i = 2; i <= n; i++) dpl[i] = min(dpl[i - 1] + 1, a[i]);
		for(i = n - 1; i >= 1; i--) dpr[i] = min(dpr[i + 1] + 1, a[i]);

		int ans = 0;
		for(i = 1; i <= n; i++)
			ans = max(ans, min(dpl[i], dpr[i]));

		cout << ans << endl;

		return 0;
	}