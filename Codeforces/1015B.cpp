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

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, m, i, j, k, u, v;
		bool ans = 1;
		string s, s1;
		char x;

		cin >> n >> s >> s1;

		for(i = 0; i < n; i++) 
			{
				if(s1[i] != s[i]) 
					{
						for(j = i; j < n; j++)
							{
								if(s[j] == s1[i])
									{
										// cout << i << " " << j << " " << s[j] << endl;

										for(k = j - 1; k >= i; k--) 
											{
												x = s[k];
												s[k] = s[k + 1];
												s[k + 1] = x;
												vs.pb(k);
											}

										// cout << s << endl;
										break;
									}
							}

						if(s1[i] != s[i]) {
							ans = 0;
							break;
						}
					}
			}

		// cout << s << endl;


		if(!ans) { cout << -1 << endl; return 0; }

		cout << vs.size() << endl;
		for(i = 0; i < vs.size(); i++) cout << vs[i] + 1 << " "; cout << endl;

		return 0;
	}