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

vector <string> vs, ansv;

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		
		// ifstream cin ("/Users/Aulene/Desktop/input.txt");
		// ofstream cout ("/Users/Aulene/Desktop/output.txt");

		// ifstream cin ("input.txt");
		// ofstream cout ("output.txt");
		
		int n, m, i, j, u, v, w;
		string s, sx, fux;

		cin >> n;
	
		for(i = 0; i < n; i++) {
			cin >> s; vs.pb(s);
		}

		sort(vs.begin(), vs.end());

		for(auto it : vs) cout << it << endl;

		cin >> m;

		while(m--) {

			vector <string> dux;

			cin >> s;

			fux = "";

			for(i = 0; i < s.size(); i++) {

				if(s[i] == '#') {

					sx = *upper_bound(vs.begin(), vs.end(), fux);
					
					int dumb = upper_bound(vs.begin(), vs.end(), fux) - vs.begin();
						
					bool fucked = 0;

					for(j = 0; j < fux.size(); j++)
						if(sx[j] != fux[j]) {
							fucked = 1;
							break;
						}

					cout << sx << " " << dumb << endl;

					if(fucked) {
						sx = dux[dux.size() - 1];
					}

					// cout << sx << endl;
					fux = sx;
				}
				else {
					fux += s[i];
				}

				dux.pb(fux);
			}

			cout << fux << endl;

			ansv.pb(fux);
		}

		for(auto it : ansv) cout << it << endl;

		return 0;
	}