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
int ans[107];
unordered_map <int> uniq;

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, e, u, v, i, j;
		int bardtimes = 0;

		cin >> n >> e;

		while(e--)
			{
				vs.clear();
				bool bard = 0;

				cin >> u;

				for(i = 0; i < u; i++)
					{
						cin >> v;
						vs.pb(v);

						if(v == 1) bard = 1; 
					}

				if(bard)
					{
						bardtimes++;
						for(i = 0; i < vs.size(); i++) ans[vs[i]]++;
					}	
				else
					{
						j = 0;

						for(i = 0; i < vs.size(); i++) j = max(j, ans[vs[i]]);
						for(i = 0; i < vs.size(); i++)
					}

			}
		return 0;
	}