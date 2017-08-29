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

int main()
	{
		lli t, i, x, n;
		lli sum, num, ans;

		cin >> t;

		while(t--)
			{
				sum = 0;
				num = 0;
				ans = 0;

				cin >> n;

				for(i=0; i<n; i++)
					cin >> a[i];

				sort(a, a+n);

				for(i=n-1; i>=0; i--)
					{
						if((sum + a[i]) * (num + 1) >= sum * num)
							{
								sum += a[i];
								num++;
							}
						else
							break;
					}

				for(i = i; i>=0; i--)
					{
						//cout << i << endl;

						ans += a[i];
					}

				ans = ans + num*sum;

				cout << ans << endl;
			}

		return 0;
	}
