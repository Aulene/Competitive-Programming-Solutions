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

int a[100007], b[100007];
vector < pair <int, int> > vs, vs2;
vector < vector <int> > ans;

bool cmp(pair <int, int> a, pair <int, int> b) 
{
	if(a.f < b.f) return 1;
	if(a.f == b.f && a.s < b.s) return 1;
	return 0;
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, m = 0, i, j, k = 0;
		pair <int, int> x;

		cin >> n;

		for(i = 0; i < n; i++)
			{
				cin >> a[i];
				x = mp(a[i], i);
				vs.pb(x), vs2.pb(x);
			}

		sort(vs.begin(), vs.end(), cmp);

		for(i = 0; i < n; i++)
			vs2[vs[i].s].s = i;

		for(i = 0; i < n; i++)
			{
				if(vs2[i].s > i)
					{
						m++; k = m - 1;
						vector <int> ai;
						ans.pb(ai);
						ans[k].pb(i + 1);
					}
				else if(vs2[i].s == i)
					{
						vector <int> ai;
						ai.pb(i + 1);
						ans.pb(ai), m++;
					}
				else
					ans[k].pb(i + 1);
			}

		cout << m << endl;
		for(i = 0; i < ans.size(); i++)
			{
				cout << ans[i].size() << " ";
				for(j = 0; j < ans[i].size(); j++)
					cout << ans[i][j] << " ";
				cout << endl;
			}
		return 0;
	}