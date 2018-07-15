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

		int n, i, j, u, v;
		bool ans = 0;
		string s, req = "abcdefghijklmnopqrstuvwxyz", fx;
		v = 0;

		cin >> s;
		n = s.size();

		// if(n > 25)
		// 	{
		// 		for(int i = 0; i < n; i++)
		// 			{
		// 				if(s[i] == 'a' && i + 25 < n)
		// 					{
		// 						fx = "";
		// 						v = 0;

		// 						for(j = 0; j < i; j++) fx += s[j];

		// 						for(j = i; j <= i + 25; j++)
		// 							if(s[j] <= req[j - i])
		// 								{
		// 									fx += req[j - i];
		// 									v++;
		// 								}

		// 						if(v == 26) ans = 1;

		// 						// cout << i << " " << j << endl;
								
		// 						for(j = i + 26; j < n; j++) fx += s[j];

		// 						if(ans)
		// 							{
		// 								ansx = fx;
		// 								break;
		// 							} 
		// 					}

		// 				if(ans) break;
		// 			}
		// 	}

		for(i = 0; i < n; i++)
			{
				if(s[i] == 'a' && v == 0)
					v++;
				else
					{
						// cout << i << " " << v << " " << req[v] << endl;
								
						if(s[i] <= req[v])
							{
								// cout << i << " " << v << " " << req[v] << endl;

								s[i] = req[v];
								v++;
							}
					}
			}

		if(v <= 25) cout << -1 << endl;
		else
		cout << s << endl;

		return 0;
	}