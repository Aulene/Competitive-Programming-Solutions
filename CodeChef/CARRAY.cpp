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
#define mid (start + end) / 2

int a[100007], dp[100007], dp2[100007], dp3[100007];
vector <int> vs;

struct node
{
	int val;
	node *l, *r;

	int merge(int a, int b)
		{
			int x;
			x = max(a, b);
			return x;
		}

	node* build(int start, int end)
		{
			if(start == end)
				{
					val = 0;
					// cout << start << " " << val.f << " " << val.s << endl;
				}
			else
				{
					l = new node, r = new node;
					l = l -> build(start, mid), r = r -> build(mid + 1, end);
					val = merge(l -> val, r -> val);
					// cout << start << " " << end << " " << val.f << " " << val.s << endl;
				}
			return this;
		}

	node* update(int start, int end, int x, int v)
		{
			if(start == end)
				{
					val = v;
					return this;
				}

			else if(x <= mid) l = l -> update(start, mid, x, v);
			else r = r -> update(mid + 1, end, x, v);

			val = merge(l -> val, r -> val);
			return this;
		}

	int query(int start, int end, int a, int b)
		{
			if(start >= a && end <= b)
				{
					return val;
				}
			else if(end < a || start > b) return 0;
			else return merge(l -> query(start, mid, a, b), r -> query(mid + 1, end, a, b));
		}
};

node tree[100007];
signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int t, n, m, i, j, k, b, idx, ans;
		vector <int> :: iterator it;

		cin >> t;

		while(t--)
			{
				ans = 0;

				cin >> n >> k >> b;
			
				for(i = 0; i < n; i++)
					{
						cin >> a[i]; 
						dp[i] = -1;
						dp3[i] = -1;
						dp2[i] = 0; 
						vs.pb(a[i]);
					}
				
				sort(vs.begin(), vs.end());

				// for(i = 0; i < vs.size(); i++) cout << vs[i] << " "; cout << endl;

				node *root = new node;
				root = root -> build(0, n - 1);

				for(i = 0; i < n; i++)
					{
						m = k * vs[i] + b;
						idx = lower_bound(vs.begin(), vs.end(), m) - vs.begin();
						// it = lower_bound(vs.begin(), vs.end(), m);

						dp[idx] = i;
						// dp3[idx - 1] = max(i, dp3[idx]);
						// else dp[idx] = 0;

						// cout << vs[i] << " " << m << " " << idx << endl;

						ans = root -> query(0, n - 1, 0, dp[i]);

						dp2[i] = ans + 1;

						root = root -> update(0, n - 1, i, dp2[i]);
					}

				// for(i = 0; i < n; i++) cout << dp[i] << " "; cout << endl;
				// // for(i = 0; i < n; i++) cout << dp3[i] << " "; cout << endl;
				// for(i = 0; i < n; i++) cout << dp2[i] << " "; cout << endl;
				// cout << dp2[n - 1] << endl;
				
				for(i = 0; i < n; i++) ans = max(ans, dp2[i]);
				cout << ans << endl;

				vs.clear();
			}
		return 0;
	}