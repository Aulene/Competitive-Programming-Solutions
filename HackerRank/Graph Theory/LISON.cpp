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

int main()
	{
		lli n, K, i, j, ans=0;
		lli nf=1, kf=1, nkf=1;

		cin >> n >> K;

		for(i=1; i<=n; i++)
			{
				nf=(nf*i)%mod;

				if(i==K)
					kf=nf%mod;

				if(i==n-K)
					nkf=nf%mod;
			}

		ans=(kf%mod*nkf%mod);
		ans=nf/ans;

		cout << ans << endl;
		return 0;
	}