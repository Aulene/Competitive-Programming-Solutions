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

int nums[207];

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		string s;
		int n, i, k, j = 0;

		cin >> s, n = s.size();
		cin >> k;

		for(i = 0; i < n; i++)
			{
				if(nums[s[i] - 'a'] == 0) j++;
				nums[s[i] - 'a']++;

			}

		if(k > n) cout << "impossible";
		else
			{
				cout << max(k - j, 0LL);
			}

		return 0;
	}