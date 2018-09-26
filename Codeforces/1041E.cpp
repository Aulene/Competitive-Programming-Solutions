#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define vi vector <int> 
#define vvi vector < vector <int> > 

set <int> mx;
int num[1007];
int vis[1007][1007];
vector < pair <int, int> > vs;
vector < vector <int> > mv(1007);

bool cmp(pair <int, int> a, pair <int, int> b)
{
	if(a.s == b.s)
		return a.f < b.f;
	return a.s > b.s;
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);

		int n, m, i, j, u, v, p;
		bool ans = 1;

		cin >> n;

		for(i = 0; i < n - 1; i++) {
			 cin >> u >> v;
			 if(u > v) swap(u, v);
			 vs.pb(mp(u, v));
		}

		sort(vs.begin(), vs.end(), cmp);

		for(i = 1; i <= n; i++) mx.insert(i);

		// cout << endl;
		// for(i = 0; i < vs.size(); i++) cout << vs[i].f << " " << vs[i].s << endl;
		// cout << endl;

		for(i = 0; i < n - 1; i++)
			{
				u = vs[i].f, v = vs[i].s;

				if(v != n) 
					{
						ans = 0;
						break;
					}

				if(!vis[u][v])
					{

						num[u]++;
						mx.erase(u);
						vis[u][v] = 1;
					}
				else num[u]++;
			}

		if(!ans) { cout << "NO" << endl; return 0; }

		for(i = 1; i <= n; i++)
			if(num[i])
				{
					p = n;

					while(num[i] > 1)
						{
							if(mx.size())
								{
									u = *mx.begin();

									if(u < i)
										{
											mx.erase(mx.begin());
											mv[p].pb(u);
											num[i]--;
											p = u;
										}
									else { ans = 0; break; }
									
								}
							else 
								{ ans = 0; break; }
						}

					mv[p].pb(i);
				}

		if(!ans) cout << "NO" << endl;
		else
			{
				cout << "YES" << endl;
				for(i = 1; i <= n; i++) {
					for(j = 0; j < mv[i].size(); j++) cout << i << " " << mv[i][j] << endl;
				}
			}
		return 0;
	}