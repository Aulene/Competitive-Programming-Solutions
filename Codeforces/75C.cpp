#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

vector <int> vs1, vs2, vs(100007);

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, m, q, i, j, u, v;
		vector <int> :: iterator it;

		cin >> n >> m >> q;

		for(i = 1; i <= sqrt(n); i++)
			if(n % i == 0)
				{
					vs1.pb(i);
					if(i != sqrt(n)) vs1.pb(n / i);
				}
		
		for(i = 1; i <= sqrt(m); i++)
			if(m % i == 0)
				{
					vs2.pb(i);
					if(i != sqrt(m)) vs2.pb(m / i);
				}

		sort(vs1.begin(), vs1.end());
		sort(vs2.begin(), vs2.end());
		it = set_intersection(vs1.begin(), vs1.end(), vs2.begin(), vs2.end(), vs.begin());

		vs.resize(it - vs.begin());

		// for(i = 0; i < vs.size(); i++) cout << vs[i] << " "; cout << endl;

		while(q--)
			{
				cin >> u >> v;
				it = upper_bound(vs.begin(), vs.end(), v);
				it--;

				j = *it;

				if(j >= u && j <= v) cout << j << endl;
				else cout << -1 << endl;
			}
		return 0;
	}