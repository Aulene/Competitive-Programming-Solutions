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

int n, k, a, b;
queue < pair <int, int> > q;

int bfs()
{
	q.p(mp(1, 0));
	pair <int, int> mx;
	int ans = 2000000000000000007;

	while(!q.empty())
		{
			mx = q.front();
			q.pop();

			if(mx.f > n || mx.s > ans) continue;
			if(mx.f == n) ans = min(ans, mx.s);

			q.p(mp(mx.f + 1, mx.s + a));
			q.p(mp(mx.f * k, mx.s + b));
		}

	return ans;
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int i, j, ans = 0;

		cin >> n >> k >> a >> b;
		
		if(k == 1)
		    {
		        cout << (n - 1) * a << endl;
		        return 0;
		    }
		   
		while(n != 1)
		    {
		        if(n < k)
			        {
			            cout << ans + (n - 1) * a << endl;
			            return 0;
			        }
		        if(n % k != 0 && n > k)
			        {
			            ans += (n % k) * a;
			            n -= (n %k);
			        }
		        if((n - n / k) * a > b && n % k == 0)
			        {
			            ans += b;
			            n /= k;
			        }
		        else
			        {
			            if((n - n / k) * a < b)
			            {
			                cout << ans + (n - 1) * a << endl;
			                return 0;
			            }
			            ans += a;
			            n--;
			        }
		    }
		
		cout << ans << endl;

		return 0;
	}