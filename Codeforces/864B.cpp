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

set <char> sx;

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, i, j, k, ans = 0;
		string s;

		cin >> n >> s;

		for(i = 0; i < n; i++)
			{
				if(s[i] >= 'A' && s[i] <= 'Z')
					{
						sx.clear();
					}
				else
					sx.insert(s[i]);
				ans = max(ans, (int) sx.size());
			}

		cout << ans << endl;

		return 0;
	}