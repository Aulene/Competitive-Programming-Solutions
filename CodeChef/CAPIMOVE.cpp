
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

bool comp(pair <lli, lli> a, pair <lli, lli> b)
{
	return a.second > b.second;
}

vector < pair <lli, lli > > pop;
map <lli, bool> g[500007];

int main()
	{
		lli t, n, i, j, u, v, ans, ansval;
		vector< pair<lli, lli> >::iterator it;

		cin >> t;

		while(t--)
			{
				scanf("%lld", &n);

				for(i=1; i<=n; i++)
					{
						scanf("%lld", &u);
						pop.pb(mp(i, u));
						g[i][i]=1;
					}

				sort(pop.begin(), pop.end(), comp);

				for(i=0; i<n-1; i++)
					{
						scanf("%lld %lld", &u, &v);
						g[u][v]=1;
						g[v][u]=1;
					}
					
				for(i=1; i<=n; i++)
					{
						bool printed=0;
						for(it=pop.begin(); it!=pop.end(); it++)
							{
								u=it->first;
								if(!g[i][u])
									{
										//cout << i << " " << u << endl;
										if(i<n)
											cout << u << " ";
										else
											cout << u << endl;
										printed=1;
										break;
									}
							}

						if(!printed)
							{
								if(i<n)
									cout << "0 ";
								else
									cout << "0\n";
							}
					}

				pop.clear();
				for(i=0; i<500007; i++)	
					g[i].clear();
			}

		return 0;
	}