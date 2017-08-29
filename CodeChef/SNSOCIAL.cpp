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

lli maxval;
vector <lli> vals;

lli a[507][507];

int main()
	{
		lli t, i, j, r, c, k, n;
		lli x, y, ans, dist, mval;
		vector < pair <lli, lli> >::iterator it;

		scanf("%lld", &t);

		while(t--)
			{
				vals.clear();
				maxval = 0; ans = 0, mval = 0;

				scanf("%lld %lld", &r, &c);

				for(i=1; i<=r; i++)
					for(j=1; j<=c; j++)
						{
							scanf("%lld", &a[i][j]);
							maxval = max(a[i][j], maxval);
						}

				for(i=1; i<=r; i++)
					for(j=1; j<=c; j++)
						if(a[i][j] == maxval)
							{
								vals.pb(i);
								vals.pb(j);
							}

				n = vals.size();

				for(i=1; i<=r; i++)
					for(j=1; j<=c; j++)
						if(a[i][j] != maxval)
							{
								mval = INT_MAX;

								for(k=0; k<n; k+=2)
									{
										x = vals[k];
										y = vals[k+1];

										dist = max(abs(i-x), abs(j-y));
										mval = min(mval, dist);

										if(mval < ans)
											break;
									}

								ans = max(ans, mval);
							}

				printf("%lld\n", ans);
			}

		return 0;
	}