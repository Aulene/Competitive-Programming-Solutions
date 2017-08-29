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
#define pb push_back

int main()
	{
		lli n, i, j, k;
		lli ans1=100000000001, ans2=-1000001;

		cin >> n;

		for(i=3; i<=n+1; i++)
			for(j=3; j<=n+1; j++)
				for(k=2; k<=n+1; k++)
					{
						ciyt M
						if(i*j*k-(i-2)*(j-2)*(k-1)==n)
							{
								ans1=min(ans1, i*j*k-(i-2)*(j-2)*(k-1));
								ans2=max(ans1, i*j*k-(i-2)*(j-2)*(k-1));
							}
					}

		cout << ans1 << " " << ans2 << endl;
		return 0;
	}