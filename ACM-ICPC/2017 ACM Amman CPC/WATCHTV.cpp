#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

int m[100007];

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int t, n, i, j, u, v, ans, ansidx;
		string s;

		cin >> t;

		while(t--)
			{
				for(i = 0; i < 100007; i++) m[i] = 0;
				ans = 0;

				cin >> n;

				for(i = 0; i < n; i++)
					{
						cin >> s >> u;
						m[u]++;
					}

				for(i = 11111; i <= 99999; i++)
					if(m[i] > ans) {
						ans = m[i];
						ansidx = i;
					}

				cout << ansidx << endl;
			}
		return 0;
	}