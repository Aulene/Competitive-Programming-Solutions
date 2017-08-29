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

lli a[100007];
lli prefix[100007];

int main()
	{
		lli n, l, b, i, j, k;
		lli sum, ans=0, cur;
		lli med;

		cin >> n >> l >> b;

		for(i=1; i<=n; i++)
			cin >> a[i];

		prefix[1]=a[1];

		for(i=2; i<=n; i++)
			prefix[i]=prefix[i-1]+a[i];

		for(k=1; k<=n; k++)
			{
				for(i=1; i<=n-k+1; i++)
					{
						med=prefix[i+k-1]-prefix[i-1];
						med/=k;

						sum=0;

						cout << k << " " << med << endl;
						for(j=i; j<=i+k-1; j++)
							{
								cout << a[j] << " ";
								sum+=abs(a[j]-med);
							}
						cout << endl << sum << endl;

						if(sum<=b)
							ans=max(ans, k);

					}
			}

		cout << ans << endl;
		return 0;
	}