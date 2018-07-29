#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

int vx[107];

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int t, n, m, i, j, u, v, ans;
		string a, b;

		cin >> t;

		while(t--)
			{
				ans = 0;
				memset(vx, 0, sizeof(vx));

				cin >> a >> b;
				n = a.size(), m = b.size();

				ans = 0;
				
				for(i = 0; i < m; i++)
					vx[b[i] - 'a']++;

				for(i = 0; i < n; i++)
					if(vx[a[i] - 'a']) {
						ans++;
						vx[a[i] - 'a']--;
					}
					else break;

				cout << ans << endl;

			}

		return 0;
	}