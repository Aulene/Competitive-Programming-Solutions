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

lli a[100007], prefix[100007], prefix2[100007];

int main()
	{
		int n, i, m, l, r, q;

		cin >> n;

		for(i=1; i<=n; i++)
			{
				cin >> a[i];
				prefix[i]=prefix[i-1]+a[i];
			}

		sort(a+1, a+n+1);

		for(i=1; i<=n; i++)
			{
				prefix2[i]=prefix2[i-1]+a[i];
			}

		cin >> m;

		while(m--)
			{
				cin >> q >> l >> r;

				if(q==1)
					cout << prefix[r]-prefix[l-1] << endl;
				else
					cout << prefix2[r]-prefix2[l-1] << endl;
			}

		return 0;
	}