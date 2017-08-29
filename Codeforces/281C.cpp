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

int a[200007], b[200007];
vector <int> u, v;

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, m, i, j, scorea, scoreb, tx;
		
		pair < pair <int, int>, pair <int, int> > ans, temp;

		vector <int> :: iterator it;
		ans = mp(mp(0, 0), mp(0, 0));

		cin >> n;

		for(i = 0; i < n; i++)
			cin >> a[i], u.pb(a[i]);

		cin >> m;

		for(i = 0; i < m; i++)
			cin >> b[i], v.pb(b[i]);

		sort(u.begin(), u.end()), sort(v.begin(), v.end());

		for(i = 0; i < n; i++)
			{
				it = upper_bound(v.begin(), v.end(), a[i]);

				if(!(it == v.end()))
					{
						tx = v.end() - it - 1;
						tx++;
					}
				else
					{
						tx = 0;
					}

				// cout << *it << " " << tx << endl;

				scorea = (n - i) * 3 + (i) * 2; 
				scoreb = tx * 3 + (m - tx) * 2;
				
				if(scorea - scoreb > ans.s.f)
					{
						ans.f.f = scorea;
						ans.f.s = scoreb;
						ans.s.f = scorea - scoreb;
					}
				else if(scorea - scoreb == ans.s.f)
					{
						if(scorea > ans.f.f)
							{
								ans.f.f = scorea;
								ans.f.s = scoreb;
								ans.s.f = scorea - scoreb;
							}
					}

				// cout << scorea << " " << scoreb << endl;
			}

		cout << ans.f.f << ":" << ans.f.s << endl;
		return 0;
	}