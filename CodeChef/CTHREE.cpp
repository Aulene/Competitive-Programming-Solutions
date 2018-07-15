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

int a[1000007], mx[1000007];

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, x, y, z, t, i, j, k, m, ans, b, c;

		cin >> t;

		while(t--)
			{
				ans = m = 0;

				cin >> n >> x >> y >> z;

				for(i = 0; i < 1000007; i++) a[i] = mx[i] = 0;

				for(i = 1; i <= sqrt(n); i++)
					{
						if(n % i == 0)
						    {

						    	a[m++] = i;
								if((n / i) != i && ((n / i) <= (1e6))) a[m++] = n / i; 
							}
					}
				
				sort(a, a + m);
				
				// cout << m << endl;
				
				for(i = 0; i < m; i++)
					if(a[i] <= x || a[i] <= y || a[i] <= z) mx[a[i]]=1;
	
				for(i = 0; i < m; i++)
					{
						if(a[i] <= x)
							{
								for(j = 0; j < m; j++)
									{
										if(a[j] <= y)
											{
												b = a[i] * a[j]; 
												c = (int) (n / b);

												if(((b * c) == n) && c <= z)
													{ if(mx[c]) ans++; }
											}
										else break;
									}
							}
						else break;
					}

					cout << ans << endl;
			}	

		return 0;
	}