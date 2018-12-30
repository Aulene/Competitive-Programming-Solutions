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

vpi vs, vs2;
multiset <pi> mx;

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
		
		int n, m, i, j, u, v, ans = 0, ct = 0;
		pi ansp, cp;

		cin >> n;

		for(i = 1; i <= n; i++) {
			cin >> u >> v;
			vs.pb({u, v});
		}

		for(i = 1; i <= n; i++) {
			cin >> u >> v;
			for(auto it : vs) {
				mx.insert({it.f + u, it.s + v});
				vs2.pb({it.f + u, it.s + v});
			}
				
		}

		// for(auto it : mx) {
		// 	u = mx.count(it);
		// 	if(u > ans) {
		// 		ans = u;
		// 		ansp = it;
		// 	}
		// }

		sort(vs2.begin(), vs2.end());

		for(i = 0; i < vs2.size(); i++) {
			cp = vs2[i];
			ct = 0;

			for(j = i; j < vs2.size(); j++) 
				if(vs2[j] == cp) ct++;
				else break;
				
			i = j - 1;
			if(ans < ct) {
				ans = ct;
				ansp = cp;
			}
		}

		cout << ansp.f << " " << ansp.s << endl;

		return 0;
	}