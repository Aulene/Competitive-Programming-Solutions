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

const int N = 27

int a[N][N], b[N][N], c[N][N];
int n, m;

bool check() {

	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			if(c[i][j] != b[i][j]) return 0;
	return 1;
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
		
		// ifstream cin ("usaco.in");
		// ofstream cout ("usaco.out");
		
		int i, j, u, v;

		cin >> n >> m;

		for(i = 1; i <= n; i++) 
			for(j = 1; j <= m; j++) cin >> a[i][j], b[i][j] = j, c[i][j] = a[i][j];

		if(check()) {
			cout << "YES\n"; return 0;
		}

		
		return 0;
	}
