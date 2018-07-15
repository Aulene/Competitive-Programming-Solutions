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

stack <int> ans;

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int t, n, m, i, j;
		int a, b;

		cin >> t;

		while(t--)
			{
				bool p = 0;

				cin >> a >> b;

				while(a || b)
					{
						i = a % 10;
						j = b % 10;

						ans.p((i + j) % 10);
						a /= 10, b /= 10;
					}

				while(!ans.empty())
					{
						if(ans.top() == 0)
							ans.pop();
						else break;
					}

				while(!ans.empty())
					{
						p = 1;
						cout << ans.top();
						ans.pop();
					}

				if(p == 0) cout << 0;

				cout << endl;
			}
		return 0;
	}