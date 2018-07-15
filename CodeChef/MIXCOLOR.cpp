#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

unordered_map <int, int> m;
int a[100007];

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int t, n, i, j;

		cin >> t;

		while(t--)
			{
				int ans = 0;

				cin >> n;

				for(i = 0; i < n; i++)
					{
						cin >> a[i];
						m[a[i]]++;
					}

				for(i = 0; i < n; i++)
					if(m[a[i]] > 1)
						{
							m[a[i]]--;
							ans++;
						}

				cout << ans << endl;
				m.clear();
				
			}
		return 0;
	}