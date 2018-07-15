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

vector < pair <int, int> > vs;
int n = 2;

void createGraph(int k)
{
	int i, j, l, r;
	vs.pb(mp(1, 2));

	// 2 nodes
	
	for(i = 1; i <= k - 1; i++)
		{
			vs.pb(mp(2, 2 + i));
			n++;
		}

	for(i = 1; i <= k - 1; i++)
		{
			for(j = 2 + k; j <= 2 * k; j++)
				vs.pb(mp(2 + i, j));
			n++;
		}

	l = 2 + k, r = 2 * k;
	while(l < r)
		{
			vs.pb(mp(l, r));
			l++, r--;
		}

	// 1 nodes
	
	for(i = 1; i <= k - 1; i++)
		vs.pb(mp(1, n + i));
	int nm = n + k - 1;

	for(i = n + 1; i <= nm; i++)
		{
			for(j = nm + 1; j <= nm + k - 1; j++)
				vs.pb(mp(i, j));
			
		}

	// cout << nm << endl;
	l = nm + 1, r = nm + k - 1;
	while(l < r)
		{
			vs.pb(mp(l, r));
			l++, r--;
		}

	n = nm + k - 1;
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int k, i, j;

		cin >> k;

		if(k == 1) cout << "YES\n2 1\n1 2\n";
		else if(k % 2 == 0) cout << "NO\n";
		else
			{
				cout << "YES\n";
				createGraph(k);
				cout << n << " " << vs.size() << endl;
				for(i = 0; i < vs.size(); i++) cout << vs[i].f << " " << vs[i].s << endl;
			}

		return 0;
	}