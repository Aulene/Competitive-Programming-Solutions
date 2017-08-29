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

lli a[2507][2507];
lli nums[2507];

int main()
	{
		ios::sync_with_stdio(false);	
		cin.tie(NULL);
		
		lli t, n, k, i, j, x, sum, inp;
		lli ans, req;
		vector <lli> :: iterator it;
		vector <lli> comp(2507);

		cin >> t;

		while(t--)
			{
				ans = 0;

				cin >> n >> k;

				x = n;

				for(i=0; i<n; i++)
					{
						cin >> nums[i];

						for(j=0; j<nums[i]; j++)
							cin >> a[i][j];

						sort(a[i], a[i] + nums[i]);
					}

				for(i=0; i<n; i++)
					{
						if(nums[i] == k)
							{
								ans += x - 1;
								x--;
								continue;
							}

						for(j=i+1; j<n; j++)
							{
								if(nums[j] == k || nums[i] + nums[j] < k)
									continue;

								it = set_union(a[i], a[i] + nums[i], a[j], a[j] + nums[j], comp.begin());
								comp.resize(it - comp.begin());

								if(comp.size() == k)
									ans++;
							}
					}

				cout << ans << endl;
			}
		return 0;
	}