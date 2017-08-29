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
#define f first
#define s second
#define pb push_back
#define mp make_pair

int d;
pair< int, pair < double, int > > coins[107]; //first = val, second.first = weight, second.second = nums

lli payBack(lli n)
{
	int i=0;
	lli weight=0;

	while(n)
		{
			while(coins[i].first<=n)
				{
					n-=coins[i].first;
					weight+=coins[i].second.first;
				}
			i++;
		}

	return weight;
}

lli recur(int index, lli owed, lli weightLeft)
{
	if(index>=d)
		return 0;

	int i;
	lli ans=10000000001, newWt, newOwed;

	for(i=0; i<coins[index].second.second; i++)
		{
			newWt=weightLeft-coins[i].second.first*i;
			newOwed=owed-coins[i].first*i;

			if(newOwed<0)
				{
					newWt+=payBack(abs(newWt));
					ans=min(ans, newWt);
				}

			ans=min(ans, recur(index+1, newOwed, newWt));
		}

	return ans;
}

int main()
	{
		lli c, k, i, u;
		lli totalWt, ans;

		cin >> c >> d >> k;

		for(i=0; i<d; i++)
			cin >> coins[i].first >> coins[i].second.first;

		for(i=0; i<k; i++)
			{
				cin >> u;
				u--;
				coins[u].second.second++;
				totalWt+=coins[u].second.first;
			}

		sort(coins, coins+d);

		ans=recur(0, c, totalWt);
		cout << ans << endl;

		return 0;
	}