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

int ans[107];

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, i;
		string s;
		char prev;
		int x = 0;

		cin >> n >> s;

		for(i = 0; i < n; i++)
			{
				if(s[i] == '0')
					continue;

				int count = 0;
				while(s[i] == '1')
					count++, i++;

				ans[x] = count;
				x++;
				if(s[i] == '0' && s[i + 1] == '0')
					{
						ans[x] = 0;
						x++;
					}
			}

		if(x == 0)
			cout << 0 << endl;
		else
			{
				for(i = 0; i < x; i++)
					cout << ans[i];
				cout << endl;
			}
		return 0;
	}