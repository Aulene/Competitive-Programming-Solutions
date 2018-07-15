#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

int s[100007];
vector <int> vs;

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, a, b, i, j, u, v, ans = 0, sum = 0;
		int fx;

		cin >> n >> a >> b >> fx;

		sum = fx;

		for(i = 2; i <= n; i++) {
			cin >> u;
			sum += u;
			vs.pb(u);
		}

		v = fx * a;

		sort(vs.begin(), vs.end());

		if(!(b * sum <= v)) 
			{
				for(i = vs.size() - 1; i >= 0; i--)
					{
						sum -= vs[i];
						ans++;
						if(b * sum <= v) break;		
					}
			}	

		cout << ans << endl;
		
		return 0;
	}