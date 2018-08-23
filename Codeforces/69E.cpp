#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define vi vector <int> 
#define vvi vector < vector <int> > 

int a[100007];
multiset <int> mx;
set <int> vs;

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);

		int n, m, i, j, u, v;

		cin >> n >> m;

		for(i = 1; i <= n; i++)
			cin >> a[i];

		for(i = 1; i <= m; i++)
			{
				mx.insert(a[i]);
				if(mx.count(a[i]) == 1) vs.insert(a[i]);
				if(mx.count(a[i]) != 1) vs.erase(a[i]);
			}

		if(!vs.empty()) cout << *vs.rbegin() << endl;
		else cout << "Nothing" << endl;

		i = 1, j = m + 1;

		while(j <= n)
			{
				auto itr = mx.find(a[i]);
				if(itr != mx.end())
				    mx.erase(itr);

				if(mx.count(a[i]) == 1) vs.insert(a[i]);
				if(mx.count(a[i]) != 1) vs.erase(a[i]);

				mx.insert(a[j]);
				if(mx.count(a[j]) == 1) vs.insert(a[j]);
				if(mx.count(a[j]) != 1) vs.erase(a[j]);
			
				if(!vs.empty()) cout << *vs.rbegin() << endl;
				else cout << "Nothing" << endl;

				i++, j++;
			}

		return 0;
	}