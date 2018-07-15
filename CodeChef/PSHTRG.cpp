#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

int n, q;
int a[100007];
vector <int> tree[5 * 100007];
int ans[5 * 100007];
vector <int> temp;

bool checktri(int x, int y, int z)
{
	if(x + y <= z || x + z <= y || y + z <= x) return 0;
	return 1;
}

vector <int> merge(vector <int> a, vector <int> b)
{
	temp.clear();

	int p1 = 0, p2 = 0;

	while(p1 < a.size() || p2 < b.size())
		{
			if(p1 == a.size() && p2 == b.size()) break;

			if(p1 == a.size()) temp.pb(b[p2]), p2++;
			else if(p2 == b.size()) temp.pb(a[p1]), p1++;
			else
				{
				 	if(a[p1] > b[p2]) temp.pb(b[p2]), p2++;
				 	else temp.pb(a[p1]), p1++;
				}
		}

	return temp;
}

int mergeAns(vector <int> a, vector <int> b)
{
	temp.clear();

	int p1 = 0, p2 = 0;

	while(p1 < a.size() || p2 < b.size())
		{
			if(p1 == a.size() && p2 == b.size()) break;

			if(p1 == a.size()) temp.pb(b[p2]), p2++;
			else if(p2 == b.size()) temp.pb(a[p1]), p1++;
			else
				{
				 	if(a[p1] > b[p2]) temp.pb(b[p2]), p2++;
				 	else temp.pb(a[p1]), p1++;
				}
		}

	int ansx = 0;
	
	for(int i = temp.size() - 3; i >= 0; i--)
		if(checktri(temp[i], temp[i + 1], temp[i + 2]))
			{
				// cout << i << " " << temp[i] + temp[i + 1] + temp[i + 2];
				ansx = temp[i] + temp[i + 1] + temp[i + 2];
				break;
			} 

	return temp;
}

int build_tree(int cur, int l, int r)
{
     if(l == r)
	     {
	            tree[cur].pb(a[l]);
	            return 0;
	     }

    int mid = (r + l) / 2, ansx = 0;
	build_tree(2 * cur + 1, l, mid); 
	build_tree(2 * cur + 2, mid + 1, r);
	tree[cur] = merge(tree[2 * cur + 1] , tree[2 * cur + 2]);

	// cout << "OPEN " << l << " " << r << endl;
	// cout << tree[cur].size() << endl;
	// for(int i = 0; i < tree[cur].size(); i++) cout << i << " " << tree[cur][i] << endl;
	 // cout << endl;

	for(int i = tree[cur].size() - 3; i >= 0; i--)
		if(checktri(tree[cur][i], tree[cur][i + 1], tree[cur][i + 2]))
			{
				// cout << i << " " << tree[cur][i] + tree[cur][i + 1] + tree[cur][i + 2];
				ansx = tree[cur][i] + tree[cur][i + 1] + tree[cur][i + 2];
				break;
			} 
	// cout << endl;

	ans[cur] = ansx;
	// cout << ans[cur] << endl;
	// cout << "CLS" << endl;

	return 0;
}

int query(int cur, int l, int r, int x, int y)
{
	if(r < x || l > y)
		return 0;

	if(x <= l && r <= y)
		return ans[cur];

	int mid = (r + l) / 2;
	return mergeAns(query(2 * cur + 1, l, mid, x, y), query(2 * cur + 2, mid + 1, r, x, y));
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int i, j, u, v, pos, val, l, r;
		int ans;

		cin >> n >> q;

		for(i = 1; i <= n; i++) cin >> a[i];

		build_tree(1, 1, n);

		while(q--)
			{
				cin >> v;

				if(v == 1)
					{
						cin >> pos >> val;
						// root = root -> update(1, n, pos, val);
					}
				else
					{
						cin >> l >> r;
						ans = query(1, 1, n, l, r);
						cout << ans << endl;
					}
			}
		return 0;
	}