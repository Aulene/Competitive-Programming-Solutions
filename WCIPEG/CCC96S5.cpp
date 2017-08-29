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
#define p push

int a[100007];
int bx[100007];

vector<int> b;

int main()
	{
		int t, n, i, j;
		int ans;
		vector<int>::iterator it;

		cin >> t;

		while(t--)
			{
				ans=0;
				cin >> n;

				for(i=n-1; i>=0; i--)	
					cin >> a[i];
				for(i=n-1; i>=0; i--)
					cin >> bx[i];

				for(i=0; i<n; i++)
					{
						//cout << a[i] << " " << bx[i] << endl;;
						b.pb(bx[i]);
					}

				for(i=0; i<n; i++)
					{
						it=upper_bound(b.begin(), b.end(), a[i]);
						
						it--;
						if(*it>=a[i])
							{
								//cout << *it << " " << a[i] << endl;
								j=it-b.begin();
								ans=max(ans, i-j);
							}
					}

				cout << "The maximum distance is " << ans << endl;
				b.clear();
			}

		return 0;
	}