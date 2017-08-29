#include<iostream>
#include<fstream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<climits>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<set>
#include<list>

using namespace std;

#define lli long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

struct trainer
{
	lli d, t, s;
};

bool cmp(trainer a, trainer b)
{
	return a.d < b.d;
}

trainer ts[100007];
priority_queue < pair <lli, lli > > pq;
pair <lli, lli> p;

int main()
	{
		lli i, j, n, k, m, t, ans;

		cin >> t;

		while(t--)
			{
				ans = j = 0;

				cin >> n >> m;

				for(i = 0; i < n; i++)
					cin >> ts[i].d >> ts[i].t >> ts[i].s;

				sort(ts, ts + n, cmp);

				for(i = 1; i <= m; i++)
					{
						while(j < n && ts[j].d == i)
							{
								pq.p(mp(ts[j].s, ts[j].t));
								j++;
							}

						if(!pq.empty())
							{
								p = pq.top();
								pq.pop();
								p.s--;

								if(p.s)
									pq.p(p);
							}
					}

				while(!pq.empty())
					{
						p = pq.top();
						pq.pop();
						ans += p.f * p.s;
						// cout << p.f << " " << p.s << endl;
					}

				cout << ans << endl;
			}

		return 0;
	}