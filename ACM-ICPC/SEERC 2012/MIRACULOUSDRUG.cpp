#include <bits/stdc++.h>

using namespace std;

#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

int a[10007], ans[10007];
bool p[10007];
vector <int> vs[10007];

int main()
	{
		ifstream cin ("g.in");

		int n, h, b, e, i, j, k, u, v, x, y, fx;
		pair <int, int> pz;

		while(cin >> n) 
			{
				cin >> h >> b >> e;
				
				for(i = 0; i < 10007; i++) vs[i].clear(), ans[i] = 0, p[i] = 0;

				for(i = 1; i <= n; i++) {
					cin >> a[i];
					vs[a[i]].pb(i);
				}
				
				u = n + 1;

				for(i = 1; i < 10007; i++)
					for(j = vs[i].size() - 1; j >= 0; j--)
						{
							v = vs[i][j];
							
							// cout << "X. " <<  i << " " << v << endl;

							fx = 0;

							for(k = 0; k < h; k++)
								{
									if(v + k > n) break;

									if(!p[v + k]) p[v + k] = 1, fx++;
								}

							ans[v] = fx;
							// cout << "ANS. " << v << " = " << ans[v] << endl;
						}
				
				for(i = b; i <= e; i++) cout << ans[i] << " "; cout << endl;
			}

		return 0;
	}