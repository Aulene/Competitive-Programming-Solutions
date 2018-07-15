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

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int u, fives = 0, twos = 0, d, n, i, j, k, count, ans = 1;
		cin >> n >> k;
		
		u = n;

		while(u % 5 == 0)
			{
				u /= 5;
				fives++;
			}

		u = n;

		while(u % 2 == 0)
			{
				u /= 2;
				twos++;
			}

		
		d = min(fives, twos);
		i = k - fives; j = k - twos;

		for(u = 0; u < i; u++)
			ans = ans * 5;
		
		for(u = 0; u < j; u++)
			ans = ans * 2;

		cout << ans * n << endl;
	    return 0;
	}