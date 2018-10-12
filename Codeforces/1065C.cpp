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

// int h[200007], pre[200007];
int a[200007];
signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		
		// ifstream cin ("/Users/Aulene/Desktop/input.txt");
		// ofstream cout ("/Users/Aulene/Desktop/output.txt");

		// ifstream cin ("input.txt");
		// ofstream cout ("output.txt");
		
		int n, k, i, j, u, v = INT_MAX, vm = 0, ans = 0, cut = 0;

		cin >> n >> k;

		// for(i = 1; i <= n; i++) cin >> u, v = min(u, v), vm = max(u, vm), h[u]++;

		// for(i = 200000; i >= 1; i--) pre[i] = h[i];
		// for(i = 200000; i >= 1; i--) h[i] += h[i + 1];
		// for(i = 200000; i >= 1; i--) pre[i] += pre[i + 1];
		// for(i = 200000; i >= 1; i--) pre[i] += pre[i + 1];
		
		// // cout << v << " " << vm << endl;
		// // for(i = v; i <= vm; i++) cout << h[i] << " "; cout << endl;
		// // for(i = v; i <= vm; i++) cout << pre[i] << " "; cout << endl;
		// // cout << endl;

		// for(i = vm; i > v; i--) {
		// 	if(h[i - 1] + pre[i] - cut > k) {
		// 		// cout << "CUT = " << i << " " << h[i - 1] + pre[i] - cut << endl; 
		// 		cut += pre[i];
		// 		ans++;
		// 	}

		// 	// for(j = v; j <= vm; j++) cout << h[j] << " "; cout << endl;
		// 	// for(j = v; j <= vm; j++) cout << pre[j] << " "; cout << endl;
		// 	// cout << endl;
		// }

		for(i = 1; i <= n; i++) cin >> a[i];
		sort(a + 1, a + n + 1, greater<int>());
		// for(i = 1; i <= n; i++) cout << a[i] << " "; cout << endl;

		u = 0;
		a[n + 1] = mod;

		for(i = 2e7; i > a[n]; i--) {
			v = u;
			while(a[u + 1] == i) {
				u++, v++;
			}

			cut += v;

			if(cut > k) {
				cut = v;
				ans++;
			}
		}

		if(cut) ans++;

		cout << ans << endl;

		return 0;
	}