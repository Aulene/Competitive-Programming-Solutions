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

int s[200007];

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int t, n, k, i, j, u, ans;

		cin >> t;

		while(t--)
			{
				for(i = 0; i < 200007; i++) s[i] = 0;

				cin >> n >> k;

				for(i = 0; i < n; i++)
					{
						cin >> u;
						s[u]++;
					}

				for(i = 0;; i++)
					{
						if(s[i] > 0) continue;
						else
							{
								if(k == 0)
									{
										ans = i;
										break;
									}
								else
									{
										k--;
										continue;
									}
							}
					}

				cout << ans << endl;
			}

		return 0;
	}