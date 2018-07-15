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

int a[1007], b[1007];

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, t, i, j, u = 0, v = 0;
		char x;
		string s1, s2, ans = "";

		cin >> n >> t >> s1 >> s2;

		for(i = 0; i < n; i++)
			{
				a[s1[i]]++;
				a[s2[i]]++;
				x = s1[i];
			}

		for(i = 'a'; i <= 'z'; i++)
			if(a[i] == 0) u++;

		if(u >= t)
			{
				for(i = 'a'; i <= 'z'; i++)
					{
						if(v == t)
							break;

						if(a[i] == 0) {
							ans += (char) i;
							v++;
						}
					}
			}
		return 0;
	}