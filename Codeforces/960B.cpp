#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

int a[1007], b[1007];
vector <int> vs;
signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, i, j, u, v, k1, k2, ans = 0;

		cin >> n >> k1 >> k2;

		u = k1 + k2;

		for(i = 0; i < n; i++) cin >> a[i];
		for(i = 0; i < n; i++) cin >> b[i];
		for(i = 0; i < n; i++) vs.pb(abs(a[i] - b[i]));

		sort(vs.begin(), vs.end(), greater <int> ());

		while(u)
			{
				if(!u) break;

				if(vs[0] > 0)
					{
						vs[0]--;
						u--;
					}
				else
					{	
						vs[0]++;
						u--;
					}
					
				sort(vs.begin(), vs.end(), greater <int> ());
			}

		if(u > 0) {
			if(u % 2 == 1) ans = 1;
		}
		else {
			for(i = 0; i < n; i++) ans += vs[i] * vs[i];
		}

		cout << ans << endl;

		return 0;
	}