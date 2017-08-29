#include<iostream>
#include<fstream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<climits>
#include<algorithm>
#include<vector>
#include<unordered_map>
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

int a[107];
unordered_map<int, int> m;

signed main()
	{
		int n, i, x, prev;
		bool first = 1, second = 1, third = 1, ans = 1;

		cin >> n >> prev;

		for(i = 1; i < n; i++)	
			{
				cin >> x;

				// cout << prev << 	" " << x << endl;
				if(x > prev)
					{
						if(!first)
							ans = 0;
					}
				else if(x == prev)
					{
						first = 0;
						if(!second)
							ans = 0;
					}
				else if(x < prev)
					{
						first = 0;
						second = 0;
						if(!third)
							ans = 0;
					}

				prev = x;
			}

		if(ans) cout << "YES" << endl;
		else cout << "NO" << endl;
 		return 0;
	}