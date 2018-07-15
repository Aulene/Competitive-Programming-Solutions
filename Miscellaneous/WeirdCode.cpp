// DOKI DOKI AARU <3 - Aulene

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

int v1[1007], v2[1007];

bool check(string s, int l)
{
	int n = s.size();

	for(int i = 'a'; i <= 'z'; i++) v2[i] = 0;

	for(int i = 0; i + l - 1 < n; i++)
		{
			for(int i = 'a'; i <= 'z'; i++) v1[i] = 0;

			int left = i, right = i + l - 1;

			for(int j = left; j <= right; j++)
				{
					if(v1[s[j]] == 0)
						{
							v1[s[j]] = 1;
							v2[s[j]]++;
						}
				}
		}

	for(char x = 'a'; x <= 'z'; x++)
		{
			// cout << l << " " << x << " " << v2[x] << endl;

			if(v2[x] == n - l + 1)
				{
					// cout << l << " " << x << endl;
					return 1;
				}
		}

	return 0;
}

int bsearch(string s)
{
	int n = s.size(), low = 1, high = n, mid, ans = 0;

	while(low <= high)
		{
			mid = (low + high) / 2;

			if(check(s, mid))
				{
					high = mid - 1;
					ans = mid;
				}
			else
				low = mid + 1;
		}

	return ans;
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int t, n, i, j;
		string s;

		cin >> t;

		while(t--)
			{
				cin >> s;
				int ans = bsearch(s);
				cout << ans << endl;
			}

		return 0;
	}