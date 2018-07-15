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

vector <int> vs;
int a[1007];
bool thr[1007];

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, k, i, j, t;

		cin >> t;

		while(t--)
			{
				int ans = 0;

				vs.clear();

				cin >> k >> n;
				for(i = 0; i < n; i++) cin >> a[i], thr[i] = 0, vs.pb(a[i]);
				
				sort(vs.begin(), vs.end());

				for(i = n - 1; i >= 0; i--) 
					{
						for(j = 0; j < n; j++)
							{
								if(vs[i] == a[j] && i != j && !thr[j])
									{
										ans++;
										thr[j] = 1;
									}
							}
					}

				cout << k << " " << ans << endl;
			}

		return 0;
	}