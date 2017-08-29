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

		int t, n, m, i, j, sum1, sum2;

		cin >> t;
		while(t--)
			{
				sum1 = sum2 = 0;

				cin >> n >> m;

				for(i = 0; i < n; i++)
					cin >> j, sum1 += j;
				for(i = 0; i < m; i++)
					cin >> j, sum2 += j;

				if(sum1 >= sum2)
					cout << "Snow" << endl;
				else
					cout << "Death" << endl;
			}
		return 0;
	}