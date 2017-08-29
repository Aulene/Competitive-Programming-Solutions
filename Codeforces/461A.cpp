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

lli a[300007];

int main()
	{
		int n, i, j=0;
		lli sum=0, ans=0;

		cin >> n;

		for(i=0; i<n; i++)
			{
				cin >> a[i];
				sum+=a[i];
			}

		sort(a, a+n);

		for(i=0; i<n-1; i++)
			{
				ans+=sum;
				sum-=a[j];
				ans+=a[j];
				j++;
			}	

		cout << ans+a[j] << endl;
		return 0;
	}