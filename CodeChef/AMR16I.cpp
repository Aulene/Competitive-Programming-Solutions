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

lli a[100007];
lli prefix[100007];
lli arr[100007];
vector<lli> pos;
lli n;

bool recur(vector<lli>::iterator it, lli sum)
{
	if(sum==0)
		return 1;

	if(sum<0 || it==pos.end() || *it>sum)
		return 0;

	vector<lli>::iterator newIndex;

	bool ans1=0, ans2=0;
	newIndex=lower_bound(pos.begin(), pos.end(), sum-*it);

	if(newIndex!=pos.end())
		ans1=recur(newIndex, sum-*it);
	ans2=recur(it+1, sum);

	return max(ans1, ans2);
}

int main()
	{
		lli t, sum, x, i;

		cin >> t;

		while(t--)
			{
				cin >> sum >> n >> x;

				for(i=1; i<=n; i++)
					cin >> a[i];

				prefix[0]=sum;
				arr[0]=sum;

				for(i=1; i<=n; i++)
					{
						sum+=a[i];
						arr[i]=prefix[i-1]+a[i];
						prefix[i]=prefix[i-1]+arr[i];
					}

				for(i=0; i<=n; i++)
					pos.pb(arr[i]);

				bool ans=recur(pos.begin(), x);

				if(ans)
					cout << "yes" << endl;
				else
					cout << "no" << endl;
			}

		return 0;
	}