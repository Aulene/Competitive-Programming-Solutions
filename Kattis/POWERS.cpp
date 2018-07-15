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
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

int modexp(int a, int b, int mod)
{
	a = a % mod;

	if(b == 0) return 1;
	else if(b == 1) return a % mod;
	else if(b % 2 == 0) return modexp((a % mod * a % mod) % mod, b / 2, mod) % mod;
	else return (a * modexp((a % mod * a % mod) % mod, b - 1, mod)) % mod;
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int a, b;

		cin >> a >> b;

		if(a % 2 == 0)
			{
				int ans = modexp(a / 2, b, a);
				cout << ans % a << endl;
			}
		else cout << 0 << endl;

		return 0;
	}