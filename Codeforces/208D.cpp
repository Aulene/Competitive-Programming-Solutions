#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

int ans[107], a[107];
vector < pair <int, int> > vs;

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, i, j, u, v, score = 0;

		cin >> n;

		for(i = 0; i < n; i++) cin >> a[i];
		
		for(i = 1; i <= 5; i++)
			{
				cin >> u;
				vs.pb(mp(u, i));
			}

		sort(vs.begin(), vs.end(), greater < pair <int, int> >());

		for(i = 0; i < n; i++)
			{
				score += a[i];

				for(j = 0; j < vs.size(); j++)
					{
						if(score >= vs[j].f)
							{
								u = score % vs[j].f;
								v = score / vs[j].f;
								score = u;
								ans[vs[j].s] += v;
							}
					}
			}

		for(i = 1; i <= 5; i++) cout << ans[i] << " ";
		cout << endl << score << endl;

		return 0;
	}