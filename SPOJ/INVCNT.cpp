#include <iostream>
/*
2

3
3
1
2

5
2
3
8
6
1

//

2
5
*/

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

#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

int a[200007];
vector < pair <int, int> > vs;

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int t, n, i, j;

		cin >> t;

		while(t--)
			{
				cin >> n;

				for(i = 0; i < n; i++) cin >> a[i];
			}
		return 0;
	}