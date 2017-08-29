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

int a[100007];
int n, k;

int maxSumSubection(int left)
{
	int sum=0, i;

	for(i=left; i<=n; i++)
		{
			if(sum + a[i] > k)
				{
					sum=sum-a[p1]+a[i];
					p1++;
				}
			else if(sum + a[i]<k)
				{
					sum+=a[i];
				}
			else
				{
					ans=min(ans, i-p1);
				}
		}

	return ans;
}

int main()
	{
		int i, sum=0;
		int p1=1, ans=1000004;

		cin >> n >> k;

		for(i=1; i<=n; i++)
			cin >> a[i];

		

		cout << ans << endl;
		return 0;
	}