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
vector <lli> rows[507], cols[507];
vector <lli> ansRows, ansCols;

lli a[507][507];

lli searchAnsInRow(lli row, lli col)
{
	vector <lli> :: iterator it1, it2;
	lli r1, r2;
	lli dist;

	it1 = lower_bound(ansRows.begin(), ansRows.end(), row);
	it2 = upper_bound(ansRows.begin(), ansRows.end(), row);

	r1 = *it1;
	r2 = *it2;

	it1 = lower_bound(rows[r1].begin(), rows[r1].end(), col);
	it2 = upper_bound(rows[r1].begin(), rows[r1].end(), col);

	if(it1 != rows[r1].end())
		dist = abs(*it1 - col);
	if(it2 != rows[r1].end())
		dist = min(dist, abs(*it2 - col));

	it1 = lower_bound(rows[r2].begin(), rows[r2].end(), col);
	it2 = upper_bound(rows[r2].begin(), rows[r2].end(), col);

	if(it1 != rows[r2].end())
		dist = min(dist, abs(*it1 - col));
	if(it2 != rows[r2].end())
		dist = min(dist, abs(*it2 - col));

	return dist;
}

lli searchAnsInCol(lli row, lli col)
{
	vector <lli> :: iterator it1, it2;
	lli c1, c2;
	lli dist;

	it1 = lower_bound(ansCols.begin(), ansCols.end(), col);
	it2 = upper_bound(ansCols.begin(), ansCols.end(), col);

	c1 = *it1;
	c2 = *it2;

	it1 = lower_bound(cols[c1].begin(), cols[c1].end(), row);
	it2 = upper_bound(cols[c1].begin(), cols[c1].end(), row);

	if(it1 != cols[c1].end())
		dist = abs(*it1 - row);
	if(it2 != cols[c1].end())
		dist = min(dist, abs(*it2 - row));

	it1 = lower_bound(cols[c2].begin(), cols[c2].end(), row);
	it2 = upper_bound(cols[c2].begin(), cols[c2].end(), row);

	if(it1 != cols[c2].end())
		dist = min(dist, abs(*it1 - row));
	if(it2 != cols[c2].end())
		dist = min(dist, abs(*it2 - row));

	return dist;
}

int main()
{
	lli t, i, j, r, c;
	lli x, y, ans, dist;
	vector < pair <lli, lli> >::iterator it;

	scanf("%lld", &t);

	while(t--)
		{
			ansRows.clear();
			ansCols.clear();

			for(i=1; i<=507; i++)
				{
					rows[i].clear();
					cols[i].clear();
				}

			maxval = 0; ans = 0;

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
							ansRows.pb(i);
							ansCols.pb(j);
							rows[i].pb(j);
							cols[j].pb(i);
						}

			for(i=1; i<=c; i++)
				sort(cols[i].begin(), cols[i].end());

			for(i=1; i<=r; i++)
				for(j=1; j<=c; j++)
					if(a[i][j] != maxval)
						{
							//cout << searchAnsInCol(i, j) << " " << searchAnsInRow(i, j) << endl;
							dist = max(searchAnsInRow(i, j), searchAnsInCol(i, j));
							ans = max(ans, dist);
						}

			printf("%lld\n", ans);
		}

	return 0;
}
