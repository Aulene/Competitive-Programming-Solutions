#include <bits/stdc++.h>
#include <unordered_map>

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
#define mid (start + end) / 2
#define pi pair <int, int>
#define N 100007

pi lazy[4 * N]; 
pi zp;
int a[N];
int n;

struct SQSTree
{
	int sqsum, sum;
	SQSTree *l, *r;

	int merge(int a, int b) { return a + b; }

	SQSTree *build(int start, int end)
		{
			if(start == end) {
				sqsum = a[start] * a[start];
				sum = a[start];
			}
			else
				{
					l = new SQSTree, r = new SQSTree;
					l = l -> build(start, mid), r = r -> build(mid + 1, end);
					sqsum = merge(l -> sqsum, r -> sqsum);
					sum = merge(l -> sum, r -> sum);
				}
			return this;
		}

	SQSTree *update0(int start, int end, int a, int b, int v, int level = 1)	
		{
			if(lazy[level] != zp)
				{
					if(lazy[level].f == 1) {
						sqsum += (2 * lazy[level].s * sum) + ((end - start + 1) * lazy[level].s * lazy[level].s);
						sum += (end - start + 1) * lazy[level].s;
					}
					else {
						sqsum = (end - start + 1) * lazy[level].s * lazy[level].s;
						sum = (end - start + 1) * lazy[level].s;
					}

					if(start != end) {
						lazy[2 * level] = lazy[level];
						lazy[2 * level + 1] = lazy[level];
					}

					lazy[level] = zp;
				}

			if(start > b || end < a)
				return this;

			if(start >= a && end <= b)
				{
					sqsum = (end - start + 1) * v * v;
					sum = (end - start + 1) * v;

					if(start != end) {
						lazy[2 * level] = mp(2, v);
						lazy[2 * level + 1] = mp(2, v);
					}	
					
					return this;		
				}

			// if(start == end)
			// 	return this;

			l = l -> update0(start, mid, a, b, v, 2 * level);
			r = r -> update0(mid + 1, end, a, b, v, 2 * level + 1);

			sqsum = merge(l -> sqsum, r -> sqsum);
			sum = merge(l -> sum, r -> sum);
			return this;
		}


	SQSTree *update1(int start, int end, int a, int b, int v, int level = 1)	
		{
			if(lazy[level] != zp)
				{
					if(lazy[level].f == 1) {
						sqsum = sqsum + (2 * lazy[level].s * sum) + ((end - start + 1) * lazy[level].s * lazy[level].s);
						sum = sum + (end - start + 1) * lazy[level].s;
					}
					else {
						sqsum = (end - start + 1) * lazy[level].s * lazy[level].s;
						sum = (end - start + 1) * lazy[level].s;
					}

					if(start != end)
						{
							lazy[2 * level] = lazy[level];
							lazy[2 * level + 1] = lazy[level];
						}

					lazy[level] = zp;
				}

			if(start > b || end < a)
				return this;

			if(start >= a && end <= b)
				{
					sqsum += (2 * v * sum) + ((end - start + 1) * v * v);
					sum += (end - start + 1) * v;

					if(start != end) {
						lazy[2 * level] = mp(1, v);
						lazy[2 * level + 1] = mp(1, v);
					}		

					return this;
				}

			// if(start == end)
			// 	return this;	

			l = l -> update1(start, mid, a, b, v, 2 * level);
			r = r -> update1(mid + 1, end, a, b, v, 2 * level + 1);
			
			sqsum = merge(l -> sqsum, r -> sqsum);
			sum = merge(l -> sum, r -> sum);
			return this;
		}

	int query(int start, int end, int a, int b, int level = 1)	
		{
			if(lazy[level] != zp)
				{
					if(lazy[level].f == 1) {
						int v1 = 2 * lazy[level].s * sum;
						int v2 = (end - start + 1) * lazy[level].s * lazy[level].s;
						sqsum = sqsum + v1 + v2;
						sum = sum + (end - start + 1) * lazy[level].s;
					}
					else {
						sqsum = (end - start + 1) * lazy[level].s * lazy[level].s;
						sum = (end - start + 1) * lazy[level].s;
					}

					if(start != end) {
						lazy[2 * level] = lazy[level];
						lazy[2 * level + 1] = lazy[level];
					}

					lazy[level] = zp;
				}

			if(start > b || end < a)
				return 0;
			else if(start >= a && end <= b)
				return sqsum;
			else
				return merge(l -> query(start, mid, a, b, 2 * level), r -> query(mid + 1, end, a, b, 2 * level + 1));
						
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
		
		int t, m, i, j, u, v, x, q;
		zp = mp(0, 0);

		cin >> t;

		for(int T = 1; T <= t; T++)
			{	
				for(i = 0; i < 4 * N; i++) lazy[i] = zp;

				cout << "Case " << T << ":" << endl;
				cin >> n >> m;

				for(i = 0; i < n; i++) cin >> a[i];

				SQSTree *sqsroot = new SQSTree;
				sqsroot = sqsroot -> build(0, n - 1);

				while(m--)
					{
						cin >> q >> u >> v;
						u--, v--;

						if(q != 2) cin >> x;

						if(q == 0)
							sqsroot = sqsroot -> update0(0, n - 1, u, v, x);
						else if(q == 1)
							sqsroot = sqsroot -> update1(0, n - 1, u, v, x);
						else {
							int ans = sqsroot -> query(0, n - 1, u, v);
							cout << ans << endl;
						}

					}
			}
		return 0;
	}