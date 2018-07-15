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

int a[257], b[257], ans[1007];

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int t, n1, n2, i, j;

		cin >> t;

		while(t--)
			{
				for(i = 0; i < 1007; i++) ans[i] = 0;

				cin >> n1;
				for(i = 0; i <= n1; i++) cin >> a[i];
				
				cin >> n2;
				for(i = 0; i <= n2; i++) cin >> b[i];

				for(i = 0; i <= n1; i++)
					for(j = 0; j <= n2; j++)
						ans[i + j] += a[i] * b[j];

				cout << n1 + n2 << endl;
				for(i = 0; i <= n1 + n2; i++) cout << ans[i] << " ";
				cout << endl;
			}
		return 0;
	}