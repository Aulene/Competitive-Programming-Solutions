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

map <char, int> mx;
vector < pair <char, int> > vs;

bool cmp(pair <char, int> a, pair <char, int> b) { return a.s > b.s; }

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
		string s, l = "", r = "", lt = "", ans = "";
		char odduse = '.';

		cin >> n >> s;

		for(i = 0; i < n; i++)
			mx[s[i]]++;

		for(auto it : mx) vs.pb(it);

		sort(vs.begin(), vs.end(), cmp);

		for(auto it : vs) {
			while(it.s--) ans += it.f;
		}
		
		//  m = vs.size();

		// for(i = 0; i < m; i++) {
		// 	if(vs[i].s % 2 == 1) {
		// 		r += vs[i].f;
		// 		vs[i].s--;
		// 		odduse = vs[i].f;

		// 		while(vs[i].s > 0) {
		// 			r += vs[i].f;
		// 			l += vs[i].f;
		// 			vs[i].s -= 2;
		// 		}

		// 		break;
		// 	}
		// }

		// for(i = 0; i < m; i++) {

		// 	if(vs[i].f == odduse) continue;

		// 	while(vs[i].s > 1) {
		// 		r += vs[i].f;
		// 		l += vs[i].f;
		// 		vs[i].s -= 2;
		// 	}
		// }

		// for(i = 0; i < m; i++) {
		// 	while(vs[i].s) {
		// 		lt += vs[i].f;
		// 		vs[i].s--;
		// 	}
		// }

		// reverse(l.begin(), l.end());

		// // cout << l << " " << r << " " << lt << endl;

		// string ans = "";
		// ans = l + r + lt;

		cout << ans << endl;
		return 0;
	}