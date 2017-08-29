//polynomial multiplication from http://www.geeksforgeeks.org/multiply-two-polynomials-2/

#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <algorithm>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <set>
#include <list>

using namespace std;

#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

long double a[107][2];
long double b[107];

long double *product(long double a[], long double b[], int n, int m)
{
	long double *ans = new long double[m + n - 1];
	int i, j;

	for(i = 0; i < m + n - 1; i++)
		ans[i] = 0;

	for(i = 0; i < n; i++)
		for(j = 0; j < m; j++)
			ans[i + j] += a[i] * b[j];

	return ans;
}	

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int t, n, i, j, N, op;		

		cin >> t;

		while(t--)
			{
				long double *ans;
				cin >> n;

				for(i = 1; i <= n; i++)
					{
						cin >> b[i];
					}

				for(i = 0; i < 107; i++)
					{
						a[i][0] = 0;
						a[i][1] = 1;
					}

				if(n == 1)
					{
						a[0][0] = sqrt(b[1]);
						a[1][0] = - sqrt(b[1]);
						N = 2;
					}
				else if(n == 2)
					{
						a[0][0] = sqrt(b[1]) + sqrt(b[2]);
						a[1][0] = sqrt(b[1]) - sqrt(b[2]);
						a[2][0] = - sqrt(b[1]) + sqrt(b[2]);
						a[3][0] = - sqrt(b[1]) - sqrt(b[2]);
						N = 4;
					}
				else
					{
						a[0][0] = sqrt(b[1]) + sqrt(b[2]) + sqrt(b[3]);
						a[1][0] = sqrt(b[1]) - sqrt(b[2]) + sqrt(b[3]);
						a[2][0] = sqrt(b[1]) + sqrt(b[2]) - sqrt(b[3]);
						a[3][0] = sqrt(b[1]) - sqrt(b[2]) - sqrt(b[3]);
						a[4][0] = - sqrt(b[1]) + sqrt(b[2]) + sqrt(b[3]);
						a[5][0] = - sqrt(b[1]) - sqrt(b[2]) + sqrt(b[3]);
						a[6][0] = - sqrt(b[1]) + sqrt(b[2]) - sqrt(b[3]);
						a[7][0] = - sqrt(b[1]) - sqrt(b[2]) - sqrt(b[3]);
						N = 8;
					}

				ans = product(a[0], a[1], 2, 2);

				for(i = 2; i < N; i++)
					ans = product(ans, a[i], i + 1, 2);

				for(i = 0; i <= N; i++) // fix ans
					if((abs(ans[i] - int(ans[i]))) > 0.5 && ans[i] > 0) ans[i] = int(ans[i]) + 1;
					else if((abs(ans[i] - int(ans[i]))) > 0.5 && ans[i] < 0) ans[i] = int(ans[i]) - 1;
					else ans[i] = (int)ans[i];

				cout << N << endl;
				for(i = 0; i <= N; i++)
					{
						if(ans[i] >= 0)
							cout << (int)ans[i] % mod << " ";
						else
							cout << mod + int(ans[i]) << " ";
					}

				cout << endl;
			}
		return 0;
	}