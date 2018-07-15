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

int g[1000001];
int p[10][1000001];

int compf(int n)
{
	int ans = 1;

	while(n)
		{
			int m = n % 10;
			if(m != 0) ans *= m;
			n /= 10;
		}

	return ans;
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int q, l, r, k, i, j;

		cin >> q;

		for(i = 1; i < 1000001; i++)
			{
				if(i < 10) g[i] = i;
				else
					{
						int n = compf(i);
						g[i] = g[n];
					}
			}

		for(i = 1; i < 1000001; i++)
			p[g[i]][i] = 1;


		for(i = 1; i < 10; i++)
			for(j = 1; j < 1000001; j++) p[i][j] += p[i][j - 1];

		while(q--)
			{
				cin >> l >> r >> k;
				cout << p[k][r] - p[k][l - 1] << endl;
			}

		return 0;
	}