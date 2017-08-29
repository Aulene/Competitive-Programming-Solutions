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
#define maxn 200500
#define f first
#define s second

lli inf = 2e9 + 2;

vector < pair < pair <lli, lli> , pair <lli, lli> > > v;
lli minCost[maxn];

int main() 
{
	lli n, x, st, end, cost, i;

	cin >> n >> x;

	for(i = 0; i < n; i++)
		{
			cin >> st >> end >> cost;
			v.pb(mp(mp(st, -1), mp(end, cost)));
			v.pb(mp(mp(end, 1), mp(st, cost)));
		}

	for(i = 0; i < maxn; i++)
		minCost[i] = inf;
	
	lli ans = inf;

	sort(v.begin(), v.end());

	//for(i = 0; i < v.size(); i++)
	//	cout << v[i].f.f << " " << v[i].f.s << " " << v[i].s.f << " " << v[i].s.s << endl;

	for(i = 0; i < v.size(); i++)
		{
			lli type = v[i].f.s;

			if(type == 1)
				{
					lli curLen = v[i].f.f - v[i].s.f + 1;
					minCost[curLen] = min(minCost[curLen], v[i].s.s);
					//cout << "Type1 " << curLen << " " << minCost[curLen] << endl;
				}
			else
				{
					lli curLen = v[i].s.f  - v[i].f.f + 1;
					if(curLen <= x)
						{
							ans = min(ans, v[i].s.s +  minCost[x - curLen]);
						}
					//cout << "Type2 " << curLen << " " << v[i].s.s + minCost[x - curLen] << " " << ans << endl;
				}
		}

	if(ans >= inf)
		ans = -1;

	cout << ans << endl;

	return 0;
}