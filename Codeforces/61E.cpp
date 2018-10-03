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

struct node
{
	int val;
	node *l, *r;

	int merge(int a, int b)
		{ return a + b; }

	node* build(int start, int end)
		{
			if(start == end)
				{ val = 0; }
			else
				{
					l = new node, r = new node;
					l = l -> build(start, mid), r = r -> build(mid + 1, end);
					val = merge(l -> val, r -> val);
					// cout << start << " " << end << " " << val.f << " " << val.s << endl;
				}
			return this;
		}

	node *update(int start, int end, int a, int b, int v)	
		{
			if(start > b || end < a)
				return this;
 
			if(start >= a && end <= b)
				{
					val += (end - start + 1) * v;
					return this;
				}
 
			l = l -> update(start, mid, a, b, v);
			r = r -> update(mid + 1, end, a, b, v);
			val = merge(l -> val, r -> val);
			return this;
		}

	int query(int start, int end, int a, int b)
		{
			if(start >= a && end <= b)
				{
					// cout << start << " " << end << endl;
					return val;
				}
			else if(end < a || start > b) {
				return ;
			}
				
			else
				return merge(l -> query(start, mid, a, b), r -> query(mid + 1, end, a, b));
		}
};

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		
		// ifstream cin ("/Users/Aulene/Desktop/input.txt");
		// ofstream cout ("/Users/Aulene/Desktop/output.txt");

		// ifstream cin ("input.txt");
		// ofstream cout ("output.txt");
		
		int n, m, i, j, u, v;

		cin >> n;
		for(i = 1; i <= n; i++) cin >> a[i];

		node *root = new node;
		root = root -> build(1, n);

		for(i = n; i >= 1; i--) {

			ans += 
		}

  		return 0;
	}