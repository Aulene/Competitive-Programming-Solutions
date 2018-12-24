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
#define vpi vector < pi >
#define ppi pair < pair <int, int>, int> 
#define zp mp(0, 0)

bool cmp(pi a, pi b) {
	if(a.s == b.s) return a.f < b.f;
	return a.s < b.s;
}

bool intersect(pair <int, int> p1, pair <int, int> p2)
{
	if(p2.f <= p1.f && p1.f <= p2.s) return 0;
	if(p2.f <= p1.s && p1.s <= p2.s) return 0;
	if(p1.f <= p2.f && p2.f <= p1.s) return 0;
	if(p1.f <= p2.s && p2.s <= p1.s) return 0;
	return 1;	
}

vpi vs;

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		
		// ifstream cin ("/Users/Aulene/Desktop/input.txt");
		// ofstream cout ("/Users/Aulene/Desktop/output.txt");

		// ifstream cin ("input.txt");
		// ofstream cout ("output.txt");
		
		int n, m, i, j, u, v, ans = 0;
		pi pz = mp(0, 0);

		cin >> n;

		for(i = 1; i <= n; i++) {
			cin >> u >> v;
			vs.pb({u, v});
		}

		sort(vs.begin(), vs.end(), cmp);

		for(i = 0; i < n; i++)
			{
				// cout << vs[i].f << " " << vs[i].s << endl;

				if(intersect(pz, vs[i])) {
					pz = vs[i];
					ans++;
				}
			}

		cout << ans << endl;

		return 0;
	}