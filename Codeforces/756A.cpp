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

lli a[107];

int main()
	{
		int n, i;
		lli ans=0, maxval=0;

		cin >> n;

		for(i=0; i<n; i++)
			{
				cin >> a[i];
				maxval=max(maxval, a[i]);
			}

		for(i=0; i<n; i++)
			ans+=maxval-a[i];

		cout << ans << endl;

		return 0;
	}