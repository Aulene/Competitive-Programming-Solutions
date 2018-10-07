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

int mina[2007], minb[2007];
int a[2007], b[2007];

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		
		// ifstream cin ("/Users/Aulene/Desktop/input.txt");
		// ofstream cout ("/Users/Aulene/Desktop/output.txt");

		// ifstream cin ("input.txt");
		// ofstream cout ("output.txt");

		int n, m, i, j, u, v, ans = 0;

		for(i = 0; i < 2007; i++) mina[i] = minb[i] = mod;

		cin >> n >> m;
		for(i = 1; i <= n; i++) cin >> a[i];
		for(i = 1; i <= m; i++) cin >> b[i];

		cin >> v;

		// for(i = 1; i <= n; i++) 
		// 	for(j = 1; j <= m; j++) if(a[i] * b[j] <= v) ans = 1;
		
		for(i = 1; i <= n; i++) {
			int sum = 0;
			for(j = i; j <= n; j++) {
				sum += a[j];
				mina[j - i + 1] = min(sum, mina[j - i + 1]);
			}
		}

		for(i = 1; i <= m; i++) {
			int sum = 0;
			for(j = i; j <= m; j++) {
				sum += b[j];
				minb[j - i + 1] = min(sum, minb[j - i + 1]);
			}
		}
		
		for(i = 1; i <= n; i++) {
			for(j = 1; j <= m; j++) {
				// cout << i << " " << mina[i] << " " << j << " " << minb[j] << endl; 
				if(mina[i] * minb[j] <= v) ans = max(ans, i * j);
			}
		}

		cout << ans << endl;

		return 0;
	}