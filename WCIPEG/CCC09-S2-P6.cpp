#include<iostream>
#include<cstdio>
#include<cstring>
#include<climits>
#include<cmath>
#include<algorithm>

using namespace std;

#define lli long long int
#define mod 1000000007

struct coin
{
	lli val;
	double wt;	
};

coin coinType[107];
lli coinsOwned[107];
lli cost, denominations, owned;

int main()
	{
		lli i, u;

		cin >> cost >> denominations >> owned;

		for(i=1; i<=denominations; i++)
			cin >> coinType[i].val >> coinType[i].wt;

		for(i=1; i<=owned; i++)
			{
				cin >> u;
				coinsOwned[u]++;
			}

		return 0;
	}