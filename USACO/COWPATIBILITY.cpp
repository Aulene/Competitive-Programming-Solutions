#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define mod 1000000007
#define int long long int
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

const int N = 500007;

vvi vs;
map <vi, int> mx;

vi get_subset(vi ar, int n) {
	vi av;
	for(int i = 0; i < 5; i++)
		if(n & (1 << i)) av.pb(ar[i]);
	return av;
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		
		// ifstream cin ("/Users/Aulene/Desktop/input.txt");
		// ofstream cout ("/Users/Aulene/Desktop/output.txt");

		// ifstream cin ("input.txt");
		// ofstream cout ("output.txt");
		
		ifstream cin ("cowpatibility.in");
		ofstream cout ("cowpatibility.out");
		
		int n, m, i, j, u, v, ans = 0;

		cin >> n;

		for(i = 0; i < n; i++) {
			vs.emplace_back();
			for(j = 0; j < 5; j++) cin >> u, vs[i].pb(u);
		}
			
		for(i = 0; i < n; i++) sort(vs[i].begin(), vs[i].end());

		sort(vs.begin(), vs.end());

		for(i = 0; i < n; i++)
			for(j = 1; j < 32; j++) {
				vi sub = get_subset(vs[i], j);
				mx[sub]++;
			}

		// for(auto it : mx) {
		// 	vi vec = it.f;
		// 	u = it.s;
		// 	for(auto it2 : vec) cout << it2 << " "; cout << endl << u << endl;
		// }

		ans = n * (n - 1) / 2;
		// cout << "ans = " << ans << endl;

		for(auto it : mx) {
			u = it.s;
			if(it.f.size() % 2 == 0) ans += (u * (u - 1)) / 2;
			else ans -= (u * (u - 1)) / 2;

			// if(u > 1) {
			// 	cout << "vec = "; for(auto it2 : vec) cout << it2 << " "; cout << endl;
			// 	cout << "u, ans = " << u << " " << ans << endl;
			// }
		}

		cout << ans << endl;

		return 0;
	}