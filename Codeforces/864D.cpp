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
#define f first
#define s second

vector <int> a, M;
unordered_map <int, int> mx;
unordered_map <int, bool> nx;

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
 
	int n, i, j = 0, ans = 0;
	cin >> n;

	a.resize(n);

	for(i = 0; i < n; i++)
		{
			cin >> a[i];
			mx[a[i]]++;
		}

	for(i = 1; i <= n; i++)
		{
			if(!mx.count(i))
				{
					M.pb(i);
					continue;
				}

			ans = ans + mx[i] - 1;
		}

	cout << ans << endl;
	
	for(i = 0; i < n; i++)
		{
			if(mx[a[i]] > 1)
				{
					if(M[j] > a[i] && !nx[a[i]]) 
						{
							cout << a[i] << " ";
							nx[a[i]] = 1;
						}
					else
						{
							cout << M[j] << " ";
							j++;
							mx[a[i]]--;
			 
						}
				}
			else cout << a[i] << " ";
		}
	cout << endl;
	return 0;
}
