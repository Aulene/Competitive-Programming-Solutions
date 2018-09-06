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
#define N 200007

vector < pair <int, int> > edges;
vi ansv;
set < pair <int, int> > vs;
vvi g(N);
int deg[N];
bool rm[N];

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);

		int n, m, k, i, j, idx, u, v, w, ans = 0;
		pair <int, int> pz;

		cin >> n >> m >> k;

		for(i = 0; i < m; i++)
			{
				cin >> u >> v;
				g[u].pb(v);
				g[v].pb(u);
				edges.pb(mp(u, v));
				deg[u]++, deg[v]++;
			}

		reverse(edges.begin(), edges.end());

		for(i = 1; i <= n; i++)
			vs.insert(mp(deg[i], i));

		// cout << endl;
		// for(auto it = vs.begin(); it != vs.end(); it++)
		// 	pz = *it, cout << pz.f << " " << pz.s << endl;

		while(vs.begin() -> first < k)
			{
				idx = vs.begin() -> second;

				if(vs.begin() -> first < k)
					{
						for(i = 0; i < g[idx].size(); i++)
							{
								u = g[idx][i];
								vs.erase(mp(deg[u], u));
								deg[u]--;
								vs.insert(mp(deg[u], u));
							}
					}
				vs.erase(mp(deg[idx], idx));
				rm[idx] = 1;
			}

		for(i = 0; i < edges.size(); i++)
			{
				cout << endl;
				for(auto it = vs.begin(); it != vs.end(); it++)
					pz = *it, cout << pz.f << " " << pz.s << endl;
				cout << i << endl;

				ansv.pb(vs.size());

				u = edges[i].f, v = edges[i].s;

				if(!rm[u] && !rm[v])
					{
						vs.erase(mp(deg[u], u));
						deg[u]--;
						vs.insert(mp(deg[u], u));	

						vs.erase(mp(deg[v], v));
						deg[v]--;
						vs.insert(mp(deg[v], v));

						while(vs.begin() -> first < k)
							{
								idx = vs.begin() -> second;

								if(vs.begin() -> first < k)
									{
										for(j = 0; j < g[idx].size(); j++)
											{
												w = g[idx][j];
												if(rm[w]) continue;
												vs.erase(mp(deg[w], w));
												deg[w]--;
												vs.insert(mp(deg[w], w));
											}
									}
								vs.erase(mp(deg[idx], idx));
								rm[idx] = 1;
							}
					}

				cout << "c " << i << endl;
			}

		reverse(ansv.begin(), ansv.end());
		for(i = 0; i < ansv.size(); i++) cout << ansv[i] << endl;
		return 0;
	}