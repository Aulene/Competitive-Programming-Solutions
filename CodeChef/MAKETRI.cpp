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

lli a[1000007];
lli ans=0;

int main()
	{
		lli n, l, r, j, i, p;
		lli x, y, z;

		cin >> n >> l >> r;

		for(i=0; i<n; i++)
			cin >> a[i];

		sort(a.begin(), a.end());

		
		cout << ans << endl;
		return 0;
	}