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

int a[N], l[N], r[N];

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

		while(cin >> n) {

			if(n == 0) break;

			int ans = 0;

			for(i = 0; i < N; i++) a[i] = l[i] = r[i] = 0;
			a[0] = LLONG_MAX;
			a[n + 1] = LLONG_MAX;

			for(i = 1; i <= n; i++) cin >> a[i];

			for(i = 1; i <= n; i++) 
				if(a[i] <= a[i - 1]) l[i] = l[i - 1] + 1;
				else l[i] = 1;

			for(i = n; i >= 1; i--)
				if(a[i] <= a[i + 1]) r[i] = r[i + 1] + 1;
				else r[i] = 1;

			for(i = 1; i <= n; i++) cout << l[i] << " "; cout << endl;
			for(i = 1; i <= n; i++) cout << r[i] << " "; cout << endl;
			
			for(i = 1; i <= n; i++) ans = max(ans, (l[i] + r[i] - 1) * a[i]);
			cout << ans << endl;
		}	
		return 0;
	}