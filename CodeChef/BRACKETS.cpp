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

struct bracket
{
	lli val, pos, identifier;
};

bool taken[17];
bracket l[17], r[17];
lli b[17], v[17];

bool compare(bracket a, bracket b)
{
	
}
int main()
	{
		lli n, k, i, x=0, y=0;

		cin >> n >> k;

		for(i=0; i<n; i++)
			cin >> v[i];

		for(i=0; i<n; i++)
			cin >> b[i];

		for(i=0; i<n; i++)
			if(v[i]<=k)
				{
					l[x].identifier=v[i];
					l[x].val=b[i];
					l[x].pos=i;
					x++;
				}
			else
				{
					r[y].identifier=v[i];
					r[y].val=b[i];
					r[y].pos=i;
					y++;
				}
		return 0;
	}