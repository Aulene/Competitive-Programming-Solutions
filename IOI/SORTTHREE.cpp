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

vector <int> vs, vx;
vector < pair <int, int> > ansv;

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		
		// ifstream cin ("/Users/Aulene/Desktop/input.txt");
		// ofstream cout ("/Users/Aulene/Desktop/output.txt");

		// ifstream cin ("input.txt");
		// ofstream cout ("output.txt");
		
		int n, m, i, j, u, v;

		cin >> n;

		for(i = 0; i < n; i++) {
			cin >> u;
			vs.pb(u);
		}

		vx = vs;
		sort(vx.begin(), vx.end());

		for(i = 0; i < vs.size(); i++) {

			if(vs[i] != vx[i]) {

				bool sw = 0;

				for(j = i + 1; j < vx.size(); j++) {
					if(vs[i] == vx[j] && vx[i] == vs[j]) {
						ansv.pb({i, j});
						swap(vs[i], vs[j]);
						sw = 1;
						break;
					}
				}

				if(!sw) {
					for(j = i + 1; j < vx.size(); j++) {
						if(vx[i] == vs[j]) {
							ansv.pb({i, j});
							swap(vs[i], vs[j]);
							sw = 1;
							break;
						}
					}
				}
			}

		}

		// for(i = 0; i < vs.size(); i++) cout << vs[i] << " "; cout << endl;
			
		cout << ansv.size() << endl;
		for(i = 0; i < ansv.size(); i++) cout << ansv[i].f + 1 << " " << ansv[i].s + 1 << endl;
		return 0;
	}