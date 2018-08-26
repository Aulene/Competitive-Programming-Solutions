#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define vi vector <int> 
#define vvi vector < vector <int> > 

bool vis[57];

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);

		int n, m, i, j, k, u, v = -1, x;
		string s, sx, ans = "";

		cin >> n >> m >> s;

		for(i = 1; i < n; i++)
			{
				u = 0;
				bool flag = 1;
				memset(vis, 0, sizeof(vis));

				// cout << i << endl;

				for(j = i; j < n; j++)
					{
						// cout << s[j] << " " << s[u] << endl;
						vis[u] = 1;

						if(s[j] != s[u])
							{
								flag = 0;
							}
						u++;
					}

				if(flag)
					{
						for(j = 0; j < n; j++)
							if(!vis[j]) {
								x = j;
								break;
							}

						v = x;
						break;
					}
			}

		// cout << v << endl;

		ans += s;
		m--;	

		if(v == -1) sx = s;
		else sx = s.substr(v);

		// cout << sx << endl;

		while(m--) ans += sx;

		cout << ans << endl;


		return 0;
	}