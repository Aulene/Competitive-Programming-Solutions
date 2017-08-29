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

lli arr[100007];

int main()
	{
		lli t, n, q, a, b, c, d, i;

		cin >> t;

		while(t--)
			{
				cin >> n >> q;

				for(i = 1; i <= n; i++)
					cin >> arr[i];

				while(q--)
					{
						bool mismatch = 0, ans = 1;

						cin >> a >> b >> c >> d;

						vector <lli> x, y;

						for(i = a; i <= b; i++)
							x.pb(arr[i]);

						for(i = c; i <= d; i++)
							y.pb(arr[i]);
						
						sort(x.begin(), x.end());
						sort(y.begin(), y.end());

						for(i=0; i <= b-a; i++)
							if(x[i] != y[i])
								{
									//cout << x[i] << " " << y[i] << endl;

									if(!mismatch)
										mismatch = 1;
									else
										ans = 0;
								}

						if(ans)
							cout << "YES" << endl;
						else
							cout << "NO" << endl;
					}
			}
		return 0;
	}