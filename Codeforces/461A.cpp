#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define vi vector <int> 
#define vvi vector < vector <int> > 

int a[300007];

int LinearSearch(int x, int n)
{
	for(int i = 1; i <= n; i++)
		if(a[i] == x) return i;
	return -1;
}

int BinarySearch(int x, int n)
{
	int low = 0, high = n - 1, mid, ans = -1;

	while(low <= high)
		{
			mid = (low + high) / 2;

			if(a[mid] == x)
				{
					ans = mid;
					break;
				}
			else if(a[mid] > x)
				high = mid - 1;
			else low = mid + 1;
		}

	return ans;
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);

		int n, m, i, j, u, v, sum, ans;

		cin >> n;

			for(i = 0; i < n; i++) cin >> a[i];

			sort(a, a + n);

			sum = 0, ans = 0;

			for(i = 0; i < n; i++) sum += a[i];

			ans += sum;

			for(i = 0; i < n - 1; i++)
				{
					ans += sum;
					sum -= a[i];
				}

			cout << ans << endl;

		return 0;
	}