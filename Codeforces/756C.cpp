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

lli n, m, k, x, y;
lli i, j, total, updown;
lli minAns, maxAns;
bool endUp;
lli sergeyAns;
map <lli, int> perrow;

lli solve()
{
	lli ans=0, i, j;
	lli left;

	ans=k/total;
	minAns=ans;
	left=k%total;

	if(left)
		maxAns=ans+1;
	else
		maxAns=ans;

	return 0;
}

int main()
	{
		cin >> n >> m >> k >> x >> y;
		total=n*m;
		updown=k/total;

		if(updown%2)
			endUp=0;
		else
			endUp=1;

		solve();

		cout << maxAns << " " << minAns << endl;
		return 0;
	}