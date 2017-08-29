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

lli a[10007];
lli prefix[100007];

map <lli, lli> occs;

int main()
	{
		lli t, n, p, i, j, sum, maxSum;

		cin >> t;

		while(t--)
			{
				maxSum = -1;

				cin >> n >> p;

				for(i=1; i<=n; i++)
					cin >> a[i];

				prefix[1]=a[1];
				for(i=2; i<=n; i++)
					prefix[i]=prefix[i-1]+a[i];

				for(i=1; i<=n; i++)
					{
						for(j=i; j<=n; j++)
							{
								sum=prefix[j]-prefix[i-1];
								sum=sum%p;

								if(sum > maxSum)
									maxSum = sum;

								occs[sum]++;
							}
					}

				cout << maxSum << " " << occs[maxSum] << endl;
				occs.clear();
			}

		return 0;
	}