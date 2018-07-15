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

		int t, n, i, j;

		cin >> t;

		while(t--)
			{
				cin >> n;

				if(n % 2 == 0)
					{
						for(i = 1, j = 2; i <= n; i += 2)
							a[i] = j, j += 2;
						for(i = 2, j = 1; i <= n; i += 2)
							a[i] = j, j += 2;
					}
				else
					{
						for(i = 1, j = 2; i < n; i += 2)
							a[i] = j, j += 2;
						for(i = 2, j = 1; i <= n; i += 2)
							a[i] = j, j += 2;
						a[n] = n;
						swap(a[n], a[n - 1]);
					}

				for(i = 1; i <= n; i++) cout << a[i] << " ";
				cout << endl;
			}
		return 0;
	}