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

#define int unsigned long long int
#define inf 100000000000000007
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

		int n, k, i, j, left = LLONG_MAX, x;
		int a1, a2;
		cin >> n >> k;

		for(i = 1; i <= k; i++) cin >> a[i];

		for(i = 1; i <= k; i++)
			{
				int diff = n / a[i];
				x = n % a[i];

				if(x < left)
					{
						left = x;
						a1 = i;
						a2 = diff;
					}
			}

		cout << a1 << " " << a2 << endl;
 		return 0;
	}