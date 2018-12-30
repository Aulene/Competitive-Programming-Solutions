#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define vi vector <int> 
#define vvi vector < vector <int> > 
#define pi pair <int, int> 
#define ppi pair < pair <int, int>, int>
#define vpi vector < pi >
#define vppi vector < ppi >
#define vvpi vector < vector < pi > >
#define zp mp(0, 0)
#define mid (start + end) / 2

const int N = 200007;
int ans[N];

bool cmp(pi a, pi b) {
	return a.s > b.s;
}

bool cmp2(vi a, vi b) {
	return a[2] > b[2];
}

struct RSTree
{
	int val;
	RSTree *l, *r;
 
	int merge(int a, int b) { return a + b; }
 
	RSTree *build(int start, int end)
		{
			if(start == end)
				val = 0;
			else
				{
					l = new RSTree, r = new RSTree;
					l = l -> build(start, mid), r = r -> build(mid + 1, end);
					val = merge(l -> val, r -> val);
				}
			return this;
		}
 
	RSTree *update(int start, int end, int a, int b)	
		{
			if(start > b || end < a)
				return this;
 
			if(start >= a && end <= b) {
				val = 1;
				return this;
			}
			
			l = l -> update(start, mid, a, b);
			r = r -> update(mid + 1, end, a, b);
			val = merge(l -> val, r -> val);
			return this;
		}
 
	int query(int start, int end, int a, int b)
		{
			if(start > b || end < a)
				return 0;
			else if(start >= a && end <= b)
				return val;
			else
				return merge(l -> query(start, mid, a, b), r -> query(mid + 1, end, a, b));
		}
};


int main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		
		int n, m, i, j, u, v, idx, ct;
		vpi vs;

		scanf("%d", &n);

		for(i = 1; i <= n; i++) {
			scanf("%d", &u);
			vs.pb({i, u});
		}

		sort(vs.begin(), vs.end(), cmp);

		scanf("%d", &m);
		
		vvi qs(m, vi(4));

		for(i = 1; i <= m; i++) {
			for(j = 0; j < 3; j++) scanf("%d", &qs[i - 1][j]);
			qs[i - 1][3] = i;
		}

		sort(qs.begin(), qs.end(), cmp2);

		ct = 0;

		RSTree *root = new RSTree;
		root = root -> build(1, n);

		for(auto it : qs) {
			u = it[0], v = it[1], j = it[2], idx = it[3];

			while(ct < vs.size() && vs[ct].s > j)
				root = root -> update(1, n, vs[ct].f, vs[ct].f), ct++;
			ans[idx] = root -> query(1, n, u, v);
		}

		for(i = 1; i <= m; i++) printf("%d\n", ans[i]);
		
		return 0;
	}