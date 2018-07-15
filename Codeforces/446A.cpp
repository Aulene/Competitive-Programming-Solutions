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

int a[100007];
int n;

int check(int m)
{
	int l, r, i, mismatches = 0, unfix = 0;

	for(i = 1; i <= m - 1; i++)
		{
			if(a[i] < a[i - 1])
				{
					if(a[i + 1] - a[i - 1] < 2) unfix++;
					mismatches++;
				}
		}

	l = 1, r = m - 1;

	while(r < n)
		{
			cout << l << " " << r << " " << mismatches << " " << unfix << endl;

			if(mismatches <= 1 && unfix == 0) return 1;

			cout << "Pre " << l << " " << r << " " << mismatches << " " << unfix << endl;

			if(a[l] < a[l - 1])
				{
					if(a[l + 1] - a[l - 1] < 2) unfix--;
					mismatches--;
				}

			cout << "1st " << l << " " << r << " " << mismatches << " " << unfix << endl;

			if(a[r + 1] < a[r])
				{
					if(a[r + 1] - a[r - 1] < 2) unfix++;
					mismatches++;
				}

			l++, r++;
			cout << "2nd " << l << " " << r << " " << mismatches << " " << unfix << endl;
			
		}

	return 0;
}

int bsearch(int low, int high)
{
	int ans = 1, mid;

	while(low <= high)
		{
			mid = (low + high) / 2;

			if(check(mid))
				{
					ans = mid;
					low = mid + 1;
				}
			else
				{
					high = mid - 1;
				}

			cout << low << " " << high << endl;
		}

	return ans;
}
int main()
	{
		int i;

		cin >> n;

		for(i = 0; i < n; i++) cin >> a[i];

		cout << check(3) << endl;

		// cout << bsearch(1, n) << endl;

		return 0;
	}