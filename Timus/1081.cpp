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

int dp[107];

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, m, x, i, j, ans;

		cin >> n >> m;

		x = pow(2, n);

		if(x < m)
			cout << -1 << endl;
		else
			{
				for(i = n - 1; i >= 0; i--)
					{
						j = pow(2, i);

						if(m == 0)
							break;

						if(m >= j)
							{
								m -= j;
								dp[i] = 1;
							}
						else
							dp[i] = 0;
					}

				for(i = n - 1; i >= 0; i--)
					cout << dp[i];
			}

		return 0;
	}