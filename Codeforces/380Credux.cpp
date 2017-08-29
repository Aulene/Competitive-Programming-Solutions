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
#define f first
#define s second
#define mid (start + end) / 2

string sx;

struct val
{
	int open, closed, complete;
};

val dummy;

struct node
{
	val ans;
	node *l, *r;

	val merge(val a, val b)
		{
			val x;
			int t;

			t = min(a.open, b.closed);
			x.complete = a.complete + b.complete + t;
			x.open = a.open + b.open - t;
			x.closed = a.closed + b.closed - t;
			return x;
		}

	node* build(int start, int end)
		{
			if(start == end)
				{
					if(sx[start] == '(')
						ans.open = 1, ans.closed = 0, ans.complete = 0;
					else
						ans.open = 0, ans.closed = 1, ans.complete = 0;
				}
			else
				{
					l = new node, r = new node;
					l = l -> build(start, mid), r = r -> build(mid + 1, end);
					ans = merge(l -> ans, r -> ans);
				}
			return this;
		}
	
	val query(int start, int end, int a, int b)
		{
			if(start >= a && end <= b)
				return ans;
			else if(end < a || start > b)
				return dummy;
			else
				return merge(l -> query(start, mid, a, b), r -> query(mid + 1, end, a, b));
		}
};

node tree[100007];

int main()
	{
		pair <int, int> vs;
		int n, i, j, u, v, m;
		val ans;

		dummy.open = 0, dummy.closed = 0, dummy.complete = 0;

		cin >> sx;
		sx = " " + sx;
		n = sx.size();

		node *root = new node;
		root = root -> build(1, n);

		cin >> m;

		while(m--)
			{
				cin >> u >> v;
				ans = root -> query(1, n, u, v);
				cout << 2 * ans.complete << endl;
			}
		return 0;
	}