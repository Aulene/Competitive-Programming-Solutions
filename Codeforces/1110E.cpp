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
int a[N], b[N];
vi d1, d2;

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
		
		int n, m, i, j, u ,v;

		cin >> n;

		for(i = 1; i <= n; i++) cin >> a[i];
		for(i = 2; i <= n; i++) d1.pb(a[i] - a[i - 1]);
		for(i = 1; i <= n; i++) cin >> b[i];
		for(i = 2; i <= n; i++) d2.pb(b[i] - b[i - 1]);

		int ans = 1;
		if(a[1] != b[1]) ans = 0;

		sort(d1.begin(), d1.end());
		sort(d2.begin(), d2.end());

		if(d1 != d2) ans = 0;
		
		if(ans) cout << "Yes\n";
		else cout << "No\n";
		return 0;
	}