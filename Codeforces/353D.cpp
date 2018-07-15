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

int a[1000007];

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		string s;
		int n, i, j, u, v, ans = 0, g = 0;

		cin >> s; n = s.size();

		for(i = 0; i < n; i++)
			if(s[i] == 'M') a[i] = 1;

		for(i = n - 1; i >= 0; i--)
			{
				if(a[i] && g) ans += g, g--;
				else if(!a[i]) g++;
			}	

		cout << ans << endl;
		return 0;
	}