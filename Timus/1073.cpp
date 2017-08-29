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

int binarySearch(int low, int high, int req)
{
	int mid, ans;

	while(low<=high)
		{
			mid=(low+high)/2;

			if(mid*mid<=req)
				{
					low=mid+1;
					ans=mid;
				}
			else
				high=mid-1;
		}

	return ans;
}

int main()
	{
		int n, f, ans=0;

		cin >> n;

		while(n)
			{
				f=binarySearch(1, 245, n);
				n=n-f*f;
				ans++;
			}

		cout << ans << endl;
		return 0;
	}