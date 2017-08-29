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

lli a[1007][1007];



int main()
	{
		int n, m, i, j;

		cin >> n >> m;

		for(i=1; i<=n; i++)
			for(j=1; j<=n; j++)
				cin >> a[i][j];


		return 0;
	}