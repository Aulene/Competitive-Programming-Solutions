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

int recur(int index, int n, int sum, vector <int> ans)
{
	if(index > n && sum == 0)
		{
			for(int i = 0; i < ans.size(); i++)
				{
					if(ans[i] > 0 && ans[i] != 1) cout << "+";
					cout << ans[i];
				}
			cout << endl;

			return 0;
		}
	if(index > n) return 0;

	vector <int> vs;
	vs = ans;

	vs.pb(index);
	recur(index + 1, n, sum + index, vs);
	
	vs = ans;
	vs.pb(-index);
	recur(index + 1, n, sum - index, vs);
	return 0;
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, i, j;

		cin >> n;
		std::vector<int> v;
		v.pb(1);
		recur(2, n, 1, v);
		return 0;
	}