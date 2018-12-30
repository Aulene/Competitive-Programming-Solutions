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

const int MAXN = 1e18;

vi p1, p2;
set <int> vs;

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
		
		int x, y, l, r, n, m, i, j, prev = -1, ans = 0;

		cin >> x >> y >> l >> r;

		j = 1;
		while(j <= max()) p1.pb(j), j *= x;
		j = 1;
		while(j <= MAXN) p2.pb(j), j *= y;

		// for(auto it : p1) cout << it << endl;
		// cout << "fuck" << endl;
		// for(auto it : p2) cout << it << endl;
		// cout << "fuck" << endl;
		
		for(auto it : p1)
			for(auto it2 : p2) vs.insert(it + it2);

		for(auto it : vs) {
			if(it >= l && it <= r) {
				// cout << it << " ";

				if(prev == -1) {
					if(it != l) ans = max(it - l, ans);
					prev = it;
					continue;
				}

				ans = max(it - prev - 1, ans);
				prev = it;
			}
		} 
		// cout << endl;
		
		ans = max(r - prev, ans);

		if(prev == -1) {
			ans = r - l + 1;
		}
		cout << ans << endl;

		return 0;
	}