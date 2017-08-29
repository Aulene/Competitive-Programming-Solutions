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

int f[200007];

void facts()
{
	f[1] = 1;
	for(int i = 2; i <= 200007; i++)
		f[i] = (f[i - 1] * i) % mod; 
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		
		facts();

		int t, i, u, v, x, y, n, denom, num;
		int right, down, ans;

		cin >> t;

		for(int j = 1; j <= t; j++)
			{
				ans = 0;
				cin >> u >> v >> x >> y;

				right = x - u;
				down = y - v;
				n = min(right, down);

				cout << "RIGHT " << right << " DOWN " << down << endl;

				for(i = 0; i <= n; i++)
					if(right + down - 2 * i >= 0)
						{
							cout << "I = " << i << endl;
							denom = (f[down - i] * f[right - i]) % mod;
							num = f[right + down - 2 * i] % mod;

							cout << "NUM = " << num << " " << "DENOM = " << denom << endl;
							if(denom > 0)
								{
									cout << num / denom << endl;
									ans += num / denom;
								}

							ans += i;

						} 

				printf("Case %lld: %lld\n", j, ans);
			}

		return 0;
	}
