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
lli bestK[10000007];

int main()
	{
		int n, i;
		lli ansL, ansR, ans=1000001, cur;

		cin >> n;
		
		for(i=1; i<=n; i++)
			{
				cin >> a[i];
				bestK[i]=a[i];
			}

		for(i=2; i<=n; i++)
			{
				
			}

		return 0;
	}