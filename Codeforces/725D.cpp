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

vpi vs;
vppi vs2;

bool cmp(pi a, pi b) { return a.f > b.f; }
bool cmp2(ppi a, ppi b) { return a.f.s - a.f.f < b.f.s - b.f.f; }

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
		
		int n, m, i, j, u, v, tp;
		int balls, curp, rem = 0, fd = 0;

		pi limak = zp;

		cin >> n >> limak.f >> limak.s;
		
		vs.pb(limak);
		balls = limak.f;

		for(i = 1; i <= n - 1; i++) {
			cin >> u >> v;
			vs.pb({u, v});
		}

		sort(vs.begin(), vs.end(), cmp);

		for(i = 0; i < n; i++) {
			if(vs[i] == limak && !fd) { curp = i + 1; fd = 1; continue; }
			vs2.pb({vs[i], i + 1});
		}

		sort(vs2.begin(), vs2.end(), cmp2);

		printf("balls = %lld\n", balls);

		for(auto it : vs2) {

			u = it.f.f, v = it.f.s, tp = it.s;

			if(tp < curp - rem) {

				cout << it.f.f << " " << it.f.s << " " << it.s;

				int req = v - u + 1;

				if(balls >= req) {
					balls -= req;
					rem++;
					cout << " rem'd";
				}
				cout << endl;
			}
		}

		cout << curp << " " << rem << endl;

		cout << curp - rem << endl;

		return 0;
	}