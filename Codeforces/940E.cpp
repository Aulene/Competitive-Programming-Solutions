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

int a[100007], pref[100007];

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, m, i, j, psize = 0, ans = 0, sum = 0, cursum = 0, psizex = 0, rem, rt;

		cin >> n >> m;
		for(i = 1; i <= n; i++) cin >> a[i];
		// sort(a + 1, a + n + 1);
		for(i = 1; i <= n; i++) pref[i] = pref[i - 1] + a[i];


		cout << endl;
		for(i = 1; i <= n; i++) cout << a[i] << " "; cout << endl;
		for(i = 1; i <= n; i++) cout << pref[i] << " "; cout << endl;
		cout << endl;

		rt = n;

		for(i = n; i >= 1; i--)
			{
				cursum = pref[rt] - pref[i - 1];
				psizex = psize + 1;
				j = floor(psizex / m);

				rem = pref[i + j - 1] - pref[i - 1];
				cursum = cursum - rem;

				cout << i << " Ai = " << a[i] << " SUM = " << sum << " CURSUM = " << cursum << endl;
				cout << "REM = " << rem << " PSIZE = " << psize << " J = " << j << endl;

				if(cursum > sum && j > 0)
					{
						cout << i << " " << sum << endl;
						ans += sum;
						sum = a[i];
						psize = 1;
						rt = i;
					}
				else
					{
						sum = cursum;
						psize++;
					}
			}

		ans += sum;
		cout << ans << endl;

		return 0;
	}