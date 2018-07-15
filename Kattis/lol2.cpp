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

unordered_map <int, int> m;
int a[100007];

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int t, n, k, i, j;

		srand(time(NULL));

		cin >> t;

		while(1)
			{
				bool ans = 1, ans2 = 1;
				
				// cin >> n >> k;

				n = rand() % 10;
				k = rand() % 10;

				// for(i = 0; i < n; i++)
				// 	cin >> a[i], m[a[i]]++;

				for(i = 0; i < n; i++)
					{
						a[i] = rand() % 10;
						m[a[i]]++;
					}
		
				for(i = 0; i < n; i++)
					{
						int f = k - a[i];

						if(m[f] && f < a[i]) ans = 0;
						m[a[i]]--;
					}

				if(ans) cout << "GOOD\n";
				else cout << "BAD\n";

				m.clear();
			}

		return 0;
	}