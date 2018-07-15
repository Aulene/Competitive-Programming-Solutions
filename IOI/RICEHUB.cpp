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

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

int a[100007];
int prefix[100007];

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, r, b, i, j, bl, anshere, ans = 0;
		int left, right, ansr, ansl, sum;

		cin >> n >> r >> b;

		for(i = 1; i <= n; i++)
			cin >> a[i], prefix[i] = prefix[i - 1] + a[i];

		for(i = 1; i <= n; i++)
			{
				// vector <int> v;

				left = right = i;
				anshere = 1, sum = 0;

				// cout << "OPEN " << i << endl;
				while(true)
					{
						ansr = ansl = 2000000000000007;

						// cout << right - left + 1 << endl;
						// cout << "LEFT = " << left << " RIGHT = " << right << endl;
						// cout << "PREFIX RIGHT = " << prefix[right + 1] - prefix[left] << " PREFIX LEFT = " << prefix[right] - prefix[left - 1] << endl;
						if(right + 1 <= n)
							ansr = sum + abs(a[right + 1] - a[i]);
						if(left - 1 >= 1)
							ansl = sum + abs(a[i] - a[left - 1]);

						// cout << "ANSR = " << ansr << " ANSL = " << ansl << endl;
						if(ansr < ansl && ansr <= b)
							right++, sum = ansr;
						else if(ansl <= b)
							left--, sum = ansl;
						else
							break;
					}

				// cout << i << " " << left << " " << right << endl;
				// cout << "CLOSE" << endl;
				// for(j = 0; j < n; j++)
				// 	v.pb(abs(a[i] - a[j]));	
				// sort(v.begin(), v.end());

				// for(j = 0; j < n; j++)
				// 	if(bl - v[j] >= 0)
				// 		anshere++, bl -= v[j];
				// 	else
				// 		break;

				anshere = right - left + 1;
				ans = max(ans, anshere);
			}

		cout << ans << endl;
		return 0;
	}