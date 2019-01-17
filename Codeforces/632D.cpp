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

const int N = 1000007;
int a[N], ans[N];

vvi cnt(N);

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

		int n, m, i, j, u, v, ansm = 0;

		cin >> n >> m;

		for(i = 1; i <= n; i++) {
			cin >> a[i]; 
			if(a[i] <= m) cnt[a[i]].pb(i);
		}

		for(i = 1; i <= m; i++) {
			if(!cnt[i].size()) continue;
			for(j = i; j <= m; j += i) ans[j] += cnt[i].size();
		}

		for(i = 1; i <= m; i++)
			if(ans[i] > ans[ansm]) ansm = i;

		vi ansv;

		for(i = 1; i <= ansm; i++)
			if(ansm % i == 0) {
				for(auto it : cnt[i]) ansv.pb(it);
			}

		sort(ansv.begin(), ansv.end());

		if(ansm == 0) ansm = 1;

		cout << ansm << " " << ans[ansm] << endl;
		for(auto it : ansv) cout << it << " "; cout << endl;

		return 0;	
	}