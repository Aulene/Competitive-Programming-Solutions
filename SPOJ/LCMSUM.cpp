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

int ans[1000007];

int gcd(int a, int b)
{
	if(a == 0) return b;
	return gcd(b % a, a);
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int t, n, i;

		cin >> t;

		while(t--)
			{
				int ans = 0;
				
				cin >> n;
				for(i = 1; i <= 1000000; i++)
					ans += (i * n) / (gcd(i, n)); 
			}
		return 0;
	}