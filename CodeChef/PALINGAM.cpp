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

int o[207], p[207];


signed main()
	{
		ios_base::sync_with_stdio(false	);
		cin.tie(NULL);

		int t, n, i, j, x, y, ans;
		string s1, s2;

		cin >> t;

		while(t--)
			{
				ans = 2;
				x = y = 0;

				for(i = 0; i < 207; i++) o[i] = 0, p[i] = 0;

				cin >> s1 >> s2;
				n = s1.size();

				for(i = 0; i < n; i++) o[s1[i]]++, p[s2[i]]++;

				for(i = 'a'; i <= 'z'; i++) if(o[i] >= 2 && p[i] == 0) ans = 1;

				for(i = 'a'; i <= 'z'; i++)
					if(o[i] > 0 && p[i] == 0) x++;
					else if(p[i] > 0 && o[i] == 0) y++;

				if(ans == 1 || (x > 0 && y == 0)) cout << 'A' << endl;
				else cout << 'B' << endl;
			}
		return 0;
	}