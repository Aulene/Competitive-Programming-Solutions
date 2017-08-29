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

int a[10007];

int main()
{
	int t, n, i, cur, ans, j;

	cin >> t;

	while(t--)
		{
			ans=1000000001;

			cin >> n;

			for(i=0; i<n; i++)
				cin >> a[i];

			sort(a, a+n, greater<int>());

			for(j=a[n-1]; j>=max(a[n-1]-4, 0); j--)
				{
					cur=0;
					for(i=0; i<n; i++)
						{
							int x=a[i];

							while(x-5>=j)
								{
									x-=5;
									cur++;
								}
							while(x-2>=j)
								{
									x-=2;
									cur++;
								}
							while(x-1>=j)
								{
									x--;
									cur++;
								}
						}
					ans=min(ans, cur);
				}

			cout << ans << endl;
		}
		
	return 0;
}