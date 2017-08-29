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

int a[100007];

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, i, j, prev = 0, ans = 0;

		cin >> n;

		for(i = 0; i < n; i++)
			cin >> a[i];

		for(i = 0; i < n; i++)
			{
				if(i - 1 == prev)
					{
						if(a[i] > a[i - 2])
							continue;
					}
				if(a[i] > a[i - 1])
					continue;
				else
					{
						if(prev == 0)
							continue;
					}
			}
		return 0;
	}