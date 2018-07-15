#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <algorithm>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <set>
#include <list>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

int dp[100007], last[1007], p[100007];

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int t, n, i, j, u, v, ans;
		string s;	

		cin >> t;

		while(t--)
			{
				ans = 0;

				cin >> s;

				n = s.size();

				for(i = 0; i < 1007; i++) last[i] = -1, dp[i] = 0, p[i] = 0;

				dp[0] = 1, p[0] = 1;	

				for(i = 1; i <= n; i++)
					{
						if(last[s[i - 1]] != -1)
							dp[i] = (p[i - 1] - p[last[s[i - 1]]] + mod) % mod;
						else
							dp[i] = p[i - 1] % mod;

						p[i] = (p[i - 1] + dp[i]) % mod;
						last[s[i - 1]] = i - 1;
					}

				// for(i = 1; i <= n; i++) cout << dp[i] << " ";
				// 	cout << endl;
				// for(i = 1; i <= n; i++) cout << p[i] << " ";
				// 	cout << endl;
				
				cout << p[n] % mod << endl;
			}

		return 0;
	}