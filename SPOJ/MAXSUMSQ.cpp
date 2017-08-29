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

int main()
	{
		lli t, n, i;
		lli sum, maxsum, ans;

		cin >> t;

		while(t--)
			{
				maxsum=INT_MIN;
				sum=0;
				ans=0;

				cin >> n;

				for(i=0; i<n; i++)
					cin >> a[i];

				for(i=0; i<n; i++)
					{
						sum+=a[i];

						maxsum=max(maxsum, sum);

						if(sum<0)
							sum=0;
					}

				for(i=0; i<n; i++)
					{
						sum+=a[i];

						if(sum==maxsum)
							ans++;

						if(sum<0)
							sum=0;
					}

				cout << maxsum << " " << ans << endl;
			}

		return 0;
	}