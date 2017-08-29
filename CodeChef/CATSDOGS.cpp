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

bool binarySearch(lli low, lli high, lli reqd)
{
	lli mid;

	while(low<=high)
		{
			mid=(low+high)/2;

			if(mid*4==reqd)
				return 1;

			if(mid*4<reqd)
				{
					low=mid+1;
				}
			else
				{
					high=mid-1;
				}
		}

	return 0;
}

int main()
	{
		int t;
		lli c, d, l, n, m, x, maxx;
		bool ans;

		cin >> t;

		while(t--)
			{
				cin >> c >> d >> l;

				if(c>2*d)
					{
						n=d+c-2*d;
					}
				else if(c<=2*d)
					{
						n=d;
					}

				maxx=c+d;

				bool ans=binarySearch(n, maxx, l);

				if(ans)
					cout << "yes" << endl;
				else
					cout << "no" << endl;
			}

		return 0;
	}