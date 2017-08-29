#include <bits/stdc++.h>

using namespace std;
 
#define lli long long int
#define pb push_back
 
lli a[50];
vector <lli> products1, products2;
lli N, k, ans=0;

lli createProducts(lli i, lli n, lli prod)
{
	if(n == N/2)
		{
			if(i > n || prod > k)
				return 0;

			if(prod <= k/a[i])
				{
					products1.pb(prod*a[i]);
					ans++;

					createProducts(i+1, n, prod*a[i]);
					createProducts(i+1, n, prod);
				}
		}
	else
		{
			if(i >= n )
				return 0;

			if(prod <= k/a[i])
				{
					products2.pb(prod*a[i]);
					ans++;

					createProducts(i+1, n, prod*a[i]);
					createProducts(i+1, n, prod);
				}
		}

	

	return 0;
}

int main()
	{
		lli i, j, res;
		vector <lli> :: iterator it, it1;
 
		cin >> N >> k;
 
		for(i=0; i<N; i++)
			cin >> a[i];
 
		sort(a, a+N);

		products1.pb(0);
		products2.pb(0);

		createProducts(0, N/2, 1);
		createProducts(N/2+1, N, 1);

		sort(products1.begin(), products1.end());
		sort(products2.begin(), products2.end());
		
		for(it=products1.begin()+1; it!=products1.end(); it++)
			{
				lli p = *it;
				p = k/p;

				it1 = upper_bound(products2.begin(), products2.end(), p);
				it1--;

				if(*it1)
					{
						res = it1 - products2.begin();
						ans+=res;
					}
			}
		
		cout << ans << endl;

		return 0;
	}  