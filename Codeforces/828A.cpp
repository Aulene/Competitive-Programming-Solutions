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

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second


signed main()
	{
		int n, a, b, i, ans = 0, x;
		int singlepersontwo = 0;

		cin >> n >> a >> b;

		for(i = 0 ; i < n; i++)
			{
				cin >> x;

				if(x == 1)
					{
						if(a)
							{
								a--;
								
							}
						else if(b)
							{
								b--;
								singlepersontwo++;
								
							}
						else if(singlepersontwo)
							{
								singlepersontwo--;
							}
						else
							ans++;

					}
				else
					{
						if(b)
							{
								b--;
							}
						else
							ans += 2;
					}
			}

		cout << ans << endl;


		return 0;
	}