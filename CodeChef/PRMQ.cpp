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

int a[100007], smallestPrime[1000007];
bool primes[1000007];
vector <int> pv;

void sieve()
{
	for(int i = 2; i < 1000007; i++) primes[i] = 1;

	for(int i = 2; i < 1000007; i += 2) smallestPrime[i] = 2;
	
	for(int i = 3; i < 1000007; i += 2)
		if(primes[i])
			{
				smallestPrime[i] = i;
				for(int j = i; j * i < 1000007; j += 2)
					if(primes[i * j])
						primes[i * j] = 0, smallestPrime[i * j] = i;
			}

	for(int i = 2; i < 1000007; i++) if(primes[i]) pv.pb(i);
}

unordered_map <int, int> primesinLogN(int n)
{
	int ans = 0;
	unordered_map <int, int> m;
	while(n > 1) m[smallestPrime[n]]++, n /= smallestPrime[n];
	return m;
}

struct node
{
	unordered_map <int, int> val;
	node *l, *r;	

	unordered_map <int, int> merge(unordered_map <int, int> a, unordered_map <int, int> b) 
		{
		 	unordered_map <int, int> x;
		 	unordered_map <int, int> :: iterator it;

		 	for(it = a.begin(); it != a.end(); it++)
		 		x[it -> f] += it -> s;
		 	for(it = b.begin(); it != b.end(); it++)
		 		x[it -> f] += it -> s;
		 	
		 	return x;
		}

	node* build(int start, int end)
		{
			if(start == end)
				{
					val = primesinLogN(a[start]);
					return this;
				}

			l = new node, r = new node;
			l = l -> build(start, mid), r = r -> build(mid + 1, end);
			val = merge(l -> val, r -> val);
			return this;
		}

	unordered_map<int, int> query(int start, int end, int a, int b)
		{
			if(start > b || end < a)
				{
					unordered_map <int, int> x;
					return x;
				}
			else if(start >= a && end <= b)
				return val;
			else 
				return merge(l -> query(start, mid, a, b), r -> query(mid + 1, end, a, b));
		}
};

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		sieve();

		int n, i, u, v, x, y, m, ans;
		unordered_map <int, int> vs;
		vector <int> :: iterator it, it1, it2;

		cin >> n;

		for(i = 1; i <= n; i++)
			cin >> a[i];

		cin >> m;

		node *root = new node;
		root = root -> build(1, n);

		while(m--)
			{
				ans = 0;
				cin >> u >> v >> x >> y;

				vs = root -> query(1, n, u, v);

				it1 = lower_bound(pv.begin(), pv.end(), x);
				it2 = lower_bound(pv.begin(), pv.end(), y);

				if(*it2 > y)
					it2--;

				// cout << *it1 << " " << *it2 << endl;
				for(it = it1; it <= it2; it++)
					ans += vs[*it];

				cout << ans << endl;
			}

		return 0;
	}