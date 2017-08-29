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

int main()
	{
		lli t, x, y, i, ans, left, finalN;

		cin >> t;

		while(t--)
			{
				cin >> x >> y;

				finalN = x + y + 1;
				
					left = 1 + y * (y + 1) / 2;

				ans = (finalN) * (finalN + 1) / 2 - (y + 2) * (y + 1) / 2 + left; 

				//cout << finalN << endl;
				//cout << (finalN) * (finalN + 1) / 2 << " " << (y + 2) * (y + 1) / 2 << " " << left << endl;

				cout << ans << endl;
			}
		return 0;
	}