#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

vector <int> vs;
multiset <int> mx;

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, m, i, j, u, v;
		multiset <int> :: iterator it;

		cin >> n;

		for(i = 0; i < n; i++) cin >> u, vs.pb(u);

		sort(vs.begin(), vs.end());

		for(i = n - 1; i >= 0; i--)
			{
				if(!mx.empty()) 
					{
						it = --mx.end();
						u = *it;

						if(u < 2 * vs[i])
							mx.insert(vs[i]);
					}
				else
					mx.insert(vs[i]);
			}

		cout << mx.size() << endl;

		return 0;
	}