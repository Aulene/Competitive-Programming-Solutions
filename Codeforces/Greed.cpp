#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

vector <int> vol, cap;

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, i, j, u, v, x = 0;

		cin >> n;

		for(i = 0; i < n; i++) cin >> u, x += u;
		for(i = 0; i < n; i++) cin >> u, cap.pb(u);
		
		sort(cap.begin(), cap.end(), greater <int>());

		v = cap[0] + cap[1];

		if(v >= x) cout << "YES\n";
		else cout << "NO\n";

 		return 0;
	}