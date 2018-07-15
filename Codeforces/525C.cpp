#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

int a[1000007], m[1000007];
vector <int> vs;

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, i, j, u, v, ans = 0;
		vector <int> :: iterator it;

		cin >> n;

		for(i = 0; i < n; i++)
			{
				cin >> u;
				m[u]++;
				a[u]++;
				a[u - 1]++;
			}

		// for(i = 0; i < 10; i++) cout << a[i] << " "; cout << endl;

		for(i = 1; i <= 1000000; i++)
			if(a[i] >= 2)
				vs.pb(i);

		for(i = 0; i < vs.size(); i++) cout << vs[i] << " "; 

		for(i = vs.size() - 1; i >= 0; i--)
			{
				v = vs[i];

				it = upper_bound(vs.begin(), vs.end(), v);

				it--;

				if(it >= vs.begin() && it < vs.end() && v >= 1)
					{
						u = *it;
						cout << v << " " << u << endl;
						cout << "A[" << v << "] = " << a[v] << " A[" << u << "] = " << a[u] << endl;

						if(u == v)
							{
								if(a[u] >= 4) 
									ans += u * u;
							}
						else if(u == v - 1)
							{
								if(a[u] - m[v] >= 2) 
									ans += u * v;
							}
						else
							{
								if(a[u] >= 2) 
									ans += u * v;
							}
					}

				it--;

				if(it >= vs.begin() && it < vs.end() && v >= 1)
					{
						u = *it;
						cout << v << " " << u << endl;
						cout << "A[" << v << "] = " << a[v] << " A[" << u << "] = " << a[u] << endl;

						if(u == v)
							{
								if(a[u] >= 4) 
									ans += u * u;
							}
						else if(u == v - 1)
							{
								if(a[u] - m[v] >= 2) 
									ans += u * v;
							}
						else
							{
								if(a[u] >= 2) 
									ans += u * v;
							}
					}

				it--;

				if(it >= vs.begin() && it < vs.end() && v >= 1)
					{
						u = *it;
						cout << v << " " << u << endl;
						cout << "A[" << v << "] = " << a[v] << " A[" << u << "] = " << a[u] << endl;

						if(u == v)
							{
								if(a[u] >= 4) 
									ans += u * u;
							}
						else if(u == v - 1)
							{ 
								if(a[u] - m[v] >= 2) 
									ans += u * v;
							}
						else
							{
								if(a[u] >= 2) 
									ans += u * v;
							}
					}


			}

		cout << ans << endl;

		return 0;
	}