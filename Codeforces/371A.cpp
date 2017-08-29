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

int ans[3000007];

void add(int x)
{
	int v = 0, p = 1;
	while(x > 0) { int num = x % 10; if(num % 2 == 1) v += p; p *= 2; x /= 10; }
	ans[v]++;
}

void sub(int x)
{
	int v = 0, p = 1;
	while(x > 0) { int num = (x % 10) % 2; if(num) v += p; p *= 2; x /= 10; }
	ans[v]--;
}

int query(int x)
{
	int v = 0, p = 1;
	while(x > 0) { int num = (x % 10) % 2; if(num) v += p; p *= 2; x /= 10; }
	return ans[v];
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int t, n, i, j, v, u;
		char q;

		cin >> t;
		
		while(t--)
			{
				cin >> q >> u;

				if(q == '+') add(u);
				else if(q == '-') sub(u);
				else cout << query(u) << endl;
			}

		return 0;
	}