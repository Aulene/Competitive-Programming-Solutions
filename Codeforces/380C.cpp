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

stack < pair <int, int> > s;
vector < pair <int, int> > intervals;

int main()
	{
		pair <int, int> vs;
		string sx;
		int n, i, j, u, v, m;

		cin >> sx;
		n = sx.size();

		for(i = 0; i < n; i++)
			{
				if(sx[i] == '(')
					{
						s.p(mp(i + 1, -1));
					}
				else
					{
						if(!s.empty())
							{
								vs = s.top();
								s.pop();
								vs.s = i + 1;
								intervals.pb(vs);
							}
					}
			}

		sort(intervals.begin(), intervals.end());

		for(i = 0; i < intervals.size(); i++)
			cout << intervals[i].f << " " << intervals[i].s << endl;

		while(m--)
			{
				cin >> u >> v;

			}
		return 0;
	}