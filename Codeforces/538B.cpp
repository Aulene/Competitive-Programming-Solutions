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

vector <int> vs, ans;

bool quasi(int n)
{
	while(n)
		{
			int x = n % 10;
			n /= 10;

			if(x > 1) return 0;			
		}

	return 1;
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, i, j;

		cin >> n;

		for(int i = 1; i <= 1000000; i++)
			if(quasi(i)) vs.pb(i);

		while(n)
			{
				j = upper_bound(vs.begin(), vs.end(), n) - vs.begin();
				j--;

				n -= vs[j];
				ans.pb(vs[j]);
			}

		cout << ans.size() << endl;
		for(i = 0; i < ans.size(); i++) cout << ans[i] << " ";
			cout << endl;

		return 0;
	}
