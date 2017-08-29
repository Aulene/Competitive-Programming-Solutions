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

bool lodge[503007];

int main()
	{
		int n, k, i, prev, j, ans=0;

		cin >> n >> k;

		for(i=0; i<n; i++)
			cin >> lodge[i];

		for(i=0; i<n; i++)
			{
				prev=-1;

				if(i==0)
					{
						for(j=i; j<=i+k; j++)
							if(lodge[j])
								prev=j;
					}
				else
					{
						for(j=i; j<i+k; j++)
							if(lodge[j])
								prev=j;
					}

				if(prev==-1)
					break;

				i=prev;
				ans++;
			}

		if(prev!=n-1)
			ans=-1;

		cout << ans << endl;
		return 0;
	}