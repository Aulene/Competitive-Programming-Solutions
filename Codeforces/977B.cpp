#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, i, j, k, u, v, ans = 0;
		string s, sx, anss;

		cin >> n >> s;
		
		for(i = 0; i < 26; i++)
			{
				for(j = 0; j < 26; j++)
					{
						sx = "";
						sx += ('A' + i);
						sx += ('A' + j);

						u = 0;

						for(k = 0; k < n - 1; k++)
							{
								if(s[k] == sx[0] && s[k + 1] == sx[1]) {
									u++;
								} 
							}

						if(u > ans) {
							anss = sx;
							ans = u;
						}
					}
			}

		cout << anss << endl;

		return 0;
	}