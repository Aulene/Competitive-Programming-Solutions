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

// #define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

int wrongSolver(std::vector <unsigned int> a) {
	int n = a.size();
	std::vector<unsigned int> prefSum(n), sufSum(n);
	prefSum[0] = a[0];
	for (int i = 1; i < n; i++) {
		prefSum[i] = prefSum[i - 1] + a[i];
	}
	sufSum[n - 1] = a[n - 1];
	for (int i = n - 2; i >= 0; i--) {
		sufSum[i] = sufSum[i + 1] + a[i];
	}
	unsigned int mn = prefSum[0] + sufSum[0];
	int where = 1;
	for (int i = 1; i < n; i++) {
		unsigned int val = prefSum[i] + sufSum[i];
		if (val < mn) {
			mn = val;
			where = i + 1;
		}
	}
	return where;
}

vector <unsigned int> ans;

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		long long int t, n, i, j, m = 4294967296;
		int x = 100000, idx;

		cin >> t;

		while(t--)
			{
				ans.clear();

				cin >> n;
				
				idx = 0;
				j = m;

				while((j - x) > (n - idx + 1))
					j -= x, idx++;
				j -= (n - idx + 1);

				// cout << idx << endl;

				ans.pb(j / 2);
				for(i = 1; i <= (n - 1 - idx); i++) ans.pb(1); 
				for(i = 1; i <= idx; i++) ans.pb(100000);

				// cout << ans.size() << endl;
				for(i = 0; i < ans.size(); i++) cout << ans[i] << " ";
				cout << endl;
				// cout << wrongSolver(ans) << endl;
			}

		return 0;
	}