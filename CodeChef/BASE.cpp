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

int main()
	{
		long double t, n, i;
		lli ans;

		cin >> t;

		while(t--)
			{
				ans=0;

				cin >> n;

				for(i=1; i<=log(n)/log(2)+1; i++)	//Sequence from OEIS.
					ans+=floor(pow(n+0.5, 1/i))-floor(pow((n+0.2)/2, 1/i));

				if(n==1)
					cout << "INFINITY" << endl;
				else
					cout << ans << endl;
			}

		return 0;
	}