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

int a[1000007];
int prefix[1000007];

int main()
	{
		int n, k, i, sum=0, ans=0;

		cin >> n >> k;

		for(i=1; i<=n; i++)
			{
				cin >> a[i];
				sum+=a[i];
				prefix[i]=sum;
			}

		for(i=k; i<=n; i++)
			ans=max(ans, prefix[i]-prefix[i-k]);

		cout << ans << endl;
		return 0;
	}