#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

int a[200007], b[200007], p[200007];
vector <int> px;

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, q, i, j, u, v, ans;
		vector <int> :: iterator it;
				
		cin >> n >> q;

		for(i = 1; i <= n; i++) cin >> a[i], p[i] = p[i - 1] + a[i], px.pb(p[i]);
			
		it = px.begin();
	
		while(q--)
			{
				cin >> u;

				u -= v;
				v = 0;
				
				it = lower_bound(it, px.end(), u);

				if(it == px.end()) {
					ans = 0;
					it = px.begin();
				}
				else {
					v = abs(*it - u);
					ans = it - px.begin();
				}

				cout << n - ans << endl;

			}
		return 0;
	}