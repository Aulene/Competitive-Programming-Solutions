#include<iostream>
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
#define pb push_back

lli a[1000007];
lli bestSum[1000007];
lli bestK[1000007];

int main()
	{
		lli n, k, i, ans=0;
		lli sum=0;

		for(i=0; i<1000007; i++)
			{
				bestSum[i]=-1000000007;
				bestK[i]=-1000000007;
			}
			
		cin >> n >> k;

		for(i=1; i<=n; i++)
			cin >> a[i];

		for(i=1; i<=k; i++)
			sum+=a[i];

		bestK[k]=sum;
		bestSum[k]=sum;

		for(i=k+1; i<=n; i++)
			{
				bestK[i]=bestK[i-1]+a[i]-a[i-k];
				bestSum[i]=max(bestSum[i-1]+a[i], bestK[i]);
				ans=max(ans, bestSum[i]);
			}

		cout << ans << endl;

		return 0;
	}








