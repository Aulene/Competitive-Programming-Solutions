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

const int N = 100007;

int a[N], ans[N], pre[N], suf[N];

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
		
		int t, n, m, i, j, u, v;

		cin >> t;

		while(t--) {
			memset(ans, 0, sizeof(ans));
			memset(pre, 0, sizeof(pre));
			memset(suf, 0, sizeof(suf));

			cin >> n;

			a[1] = 1;
			for(i = 2; i <= n; i++) {
				cin >> u;
				a[i] = a[i - 1] + u;
			}

			// for(i = 1; i <= n; i++) cout << a[i] << " "; cout << endl;
			for(i = 1; i <= n; i++) pre[i] = pre[i - 1] + a[i];
			for(i = n; i >= 1; i--) suf[i] = suf[i + 1] + a[i];

			int l = 2, r = n - 1, idx = 3;
			int lt = 1, rt = 1;

			ans[1] = 0, ans[2] = a[n] - a[1];

			while(l <= r) {
				if(lt == rt) {
					ans[idx] = ans[idx - 1] + ((l - 1) * a[l] - pre[l - 1]) + (suf[r + 1] - (n - r) * a[l]);
					lt++, l++, idx++;
				}
				else {
					ans[idx] = ans[idx - 1] + ((l - 1) * a[r] - pre[l - 1]) + (suf[r + 1] - (n - r) * a[r]);
					rt++, r--, idx++;
				}
			}

			for(i = 1; i < n; i++) cout << ans[i] << " "; cout << ans[n] << endl;
		}	
		return 0;
	}