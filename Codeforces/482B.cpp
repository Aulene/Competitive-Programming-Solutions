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

const int N = 100007;

int a[N];
vector < pair < pair <int, int>, int> > vs;

bool cmp(ppi a, ppi b) {
	if(a.f == b.f) return a.s < b.s;
	return a.f < b.f;
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
		
		int n, m, i, j, u, v, w;

		cin >> n >> m;

		for(i = 0; i < m; i++) {
			cin >> u >> v >> w;
			vs.pb({{u, v}, w});
		}

		sort(vs.begin(), vs.end(), cmp);

		for(i = 0; i < m; i++) cout << vs[i].f.f << " " << vs[i].f.s << endl;
			
		return 0;
	}