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
#define zp mp(0, 0)

vector < pair <int, int> > vs;
int ans[1007];

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		
		// ifstream cin ("/Users/Aulene/Desktop/input.txt");
		// ofstream cout ("/Users/Aulene/Desktop/output.txt");

		// ifstream cin ("input.txt");
		// ofstream cout ("output.txt");
		
		int t, n, m, i, j, u, v, x, y;
		string s;

		cin >> t;

		while(t--) {

			vs.clear();

			cin >> n >> m;

			for(i = 1; i <= n; i++) {
				cin >> s;

				for(j = 0; j < m; j++) {
					if(s[j] == '1') {
						x = i, y = j + 1;
						u = x + y, v = x - y;
						vs.pb({u, v});
					}
				}
			}

			sort(vs.begin(), vs.end());

			for(i = 0; i < vs.size(); i++) cout << vs[i].f << " " << vs[i].s << endl;

			for(i = 0; i < vs.size(); i++) {
				x = vs[i].f, y = vs[i].s;

				for(j = 1; j < n + m - 2; j++) {

					pi pz = mp(x + d, y);
				}
			}	
		}	
		return 0;
	}