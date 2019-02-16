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
int a[N];

vi vs;

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
		
		int n, m, i, j, u, v, k, ans = 0;

		cin >> n >> m >> k;	

		for(i = 1; i <= n; i++) {
			cin >> a[i];
			if(i > 1) vs.pb(a[i] - a[i - 1]);
		}

		sort(vs.begin(), vs.end());
		reverse(vs.begin(), vs.end());

		for(i = k - 1; i < vs.size(); i++) ans += vs[i];

		// for(auto it : vs) cout << it << " "; cout << endl;
		cout << ans + k << endl;

		return 0;
	}