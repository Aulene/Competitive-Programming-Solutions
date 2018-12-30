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

const int N = 507;

char a[N][N];

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
		
		int n, m, i, j, u, v, ansx = 1;

		cin >> n >> m;

		for(i = 1; i <= n; i++)
			for(j = 1; j <= m; j++) cin >> a[i][j];

		for(i = 1; i <= n; i++)
			for(j = 1; j <= m; j++)
				if(a[i][j] == 'W') {
					if(a[i - 1][j] == 'S' || a[i][j - 1] == 'S' || a[i + 1][j] == 'S' || a[i][j + 1] == 'S')
						ansx = 0;
				}

		if(ansx) {
			cout << "Yes\n";
			for(i = 1; i <= n; i++) {
				for(j = 1; j <= m; j++)
					if(a[i][j] == '.') cout << 'D';
					else cout << a[i][j];
					cout << endl;
			}
		}
		else {
			cout << "No\n";
		}
		return 0;
	}