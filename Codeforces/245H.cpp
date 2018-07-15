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

int dp[5007][5007]; // no of palindromes starting at i with length j

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		string s;
		int n, i, j, q, u, v;

		cin >> s >> q; n = s.size();

		for(i = 0; i < n; i++)
			{
				vector <char> a, b;

				for(j = i; j < n; j++)
					{
						a.pb(s[i]);
						b = a;
						reverse(b.begin(), b.end());

						if(b == a) dp[i][j - i + 1] = 1;
					}
			}

		for(i = 0; i < q; i++)
			{
				cin >> u >> v;
			}
		return 0;
	}