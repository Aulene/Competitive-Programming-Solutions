#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<climits>
 
#define lli long long int
 
using namespace std;
 
lli n;
lli a[1000007], b[1000007];
lli prefix[1000007], diff[1000007], sum[1000007];

int main()
{
	lli i, j, ans=-1000000000;	
 
	cin >> n;
 
	for(i=1; i<=n; i++)
		{
			cin >> a[i];
 			ans=max(ans, a[i]);
		}

	for(i=1; i<=n; i++)
		{
			cin >> b[i];
			prefix[i]=prefix[i-1]+b[i];
		}
 		
 	diff[1]=a[1]-prefix[1];
 	sum[1]=a[1];

	for(i=1; i<=n; i++)
		diff[i]=max(diff[i-1], a[i]-prefix[i]);
 	for(i=1; i<=n; i++)
 		sum[i]=max(sum[i-1], a[i]+prefix[i-1]);
 	for(i=1; i<=n; i++)
 		ans=max(ans, a[i]+diff[i-1]+prefix[i-1]);
 	for(i=1; i<=n; i++)
 		ans=max(ans, a[i]+prefix[n-1]-prefix[i]+sum[i-1]);
	cout << ans << endl;
	return 0;
}
 