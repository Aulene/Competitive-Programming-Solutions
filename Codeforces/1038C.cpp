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
#define N 100007

int a[N], b[N];

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);

		int n, i, j, u, v, p;
		int ax = 0, bx = 0;

		cin >> n;

		for(i = 0; i < n; i++) cin >> a[i];
		for(i = 0; i < n; i++) cin >> b[i];

		sort(a, a + n, greater <int>());
		sort(b, b + n, greater <int>());

		i = 0, j = 0, p = 0;

		while(i < n || j < n)
			{
				if(!p)
					{
						if(i < n && j < n)
							{
								if(a[i] > b[j])
									{
										ax += a[i];
										i++;
									}
								else j++;
							}
						else if(i == n && j < n) j++;
						else if(i < n && j == n) ax += a[i], i++;

					}
				else
					{
						if(i < n && j < n)
							{
								if(b[j] > a[i])
									{
										bx += b[j];
										j++;
									}
								else i++;
							}
						else if(i == n && j < n) bx += b[j], j++;
						else i++;
					}

				p = (p + 1) % 2;
				// cout << ax << " " << bx << " " << i << " " << j << endl;
			}

		cout << (ax - bx) << endl;
		return 0;
	}