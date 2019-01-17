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
#define vvvi vector < vector < vector <int> > >
#define pi pair <int, int> 
#define ppi pair < pair <int, int>, int>
#define vpi vector < pi >
#define vppi vector < ppi >
#define vvpi vector < vector < pi > > 
#define zp mp(0, 0)

const int N = 100007;

vvvi vs(N);

bool cmp(vi a, vi b) { return a[0] < b[0]; }

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
		
		int n, m, i, j, k, u, v, ans = LLONG_MAX;
		string s;

		cin >> n;

		for(i = 0; i < n; i++) {
			cin >> m >> s;
			sort(s.begin(), s.end());

			vi v(4);

			v[0] = m;

			for(j = 0; j < s.size(); j++) {
				if(s[j] == 'A') v[1]++;
				else if(s[j] == 'B') v[2]++;
				else if(s[j] == 'C') v[3]++;
			}

			// for(auto it : v) cout << it << " "; cout << endl;
			vs[0].pb(v);
			if(v[1]) vs[1].pb(v);
			if(v[2]) vs[2].pb(v);
			if(v[3]) vs[3].pb(v);
		}

		for(i = 0; i < 4; i++)
			sort(vs[i].begin(), vs[i].end(), cmp);

		for(i = 0; i < n; i++) {
			for(j = i + 1; j < n; j++) {

				vi v(4);
				int c = 0;

				for(k = 0; k < 4; k++) {
					v[k] = vs[0][i][k];
					v[k] += vs[0][j][k];
				}
					
				c = v[0];

				for(k = 1; k < 4; k++)
					if(!v[k]) c += v[k][0];
				ans = min(ans, c);
			}
		}

		cout << ans << endl;

		return 0;
	}