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
int mx[1007][1007];

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

		cin >> n >> m;

		for(i = 0; i < m; i++) {
			cin >> u >> v;
			mx[u][v] = mx[v][u] = 1;
		}

		for(i = 1; i <= n; i++) {
			for(j = i + 1; j <= n; j++) {
				if(!mx[i][j]) vs.pb({i, j});
			}
		}

		cout << vs.size() << endl;
		for(auto it : vs) cout << it.f << " " << it.s << endl;
	}