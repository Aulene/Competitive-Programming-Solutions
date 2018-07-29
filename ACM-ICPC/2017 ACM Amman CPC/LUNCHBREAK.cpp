#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

int m[7];

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int t, n, a, b, c, i, j, ans, ansidx;

		cin >> t;

		while(t--)
			{
				ans = INT_MAX;

				for(i = 0; i < 3; i++)
					cin >> m[i];

				for(i = 0; i < 3; i++)
					if(m[i] < ans) {
						ans = m[i];
						ansidx = i + 1;
					}

				if(ansidx == 1) cout << "First" << endl;
				else if(ansidx == 2) cout << "Second" << endl;
				else cout << "Third" << endl;
			}

		return 0;
	}