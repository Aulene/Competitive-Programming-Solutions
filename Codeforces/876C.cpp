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

int calc(int n) 
{
	int ans = 0;
	while(n) 
		{
			ans += n % 10;
			n /= 10;
		}

	return ans;
}

vector <int> vs;

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, k, i, j, u, v;

		cin >> n;

		for(i = n; i >= max(1 * 1LL, n - 1000); i--)
			{
				if(i + calc(i) == n) vs.pb(i);
			}

		sort(vs.begin(), vs.end());

		cout << vs.size() << endl;
		for(i = 0; i < vs.size(); i++) cout << vs[i] << " ";
		return 0;
	}