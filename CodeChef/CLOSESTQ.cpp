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

vector < pair<lli, lli> > v;

int main()
	{
		lli t, n=0, i, j, x, y;
		vector < pair <lli, lli> > ::iterator it;
		pair< lli, lli> f;

		char op;

		cin >> t;

		while(t--)
			{
				lli ans=100000000007, ansh;

				cin >> op >> x >> y;

				if(op=='+')
					{
						v.pb(mp(x, y));
						n++;
					}
				else
					{
						f.first = x;
						f.second = y;

						for(i=0; i<n; i++)
							if(v[i] == f)
								{
									v.erase(v.begin() + i);
									break;
								}

						n--;
					}

				if(n<2)
					cout << "0" << endl;
				else
					{
						for(i=0; i<n; i++)
							{
								for(j=i+1; j<n; j++)
									{
										ansh = pow(v[i].first-v[j].first, 2)+pow(v[i].second-v[j].second, 2);
										ans=min(ans, ansh);
									}
							}

						cout << ans << endl;
					}
			}

		return 0;
	}