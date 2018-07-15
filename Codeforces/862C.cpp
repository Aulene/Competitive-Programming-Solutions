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

vector <int> ans;

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, m, i, j, num1, num2, k;

		cin >> n >> m;

		if(n <= 2)
			{
				if(m == 0 && n == 2)
					cout << "NO\n";
				else
					{
						cout << "YES" << endl;
						cout << m << " ";
						if(n == 2) cout << 0 << endl;
					}
			}
		else
			{
				num1 = n, num2 = 0, k = 0, j = 0;

				while(num1-- > 2)
					{

						j ^= num2;
						ans.pb(num2++);
					}

				if(j == m)
					{
						j ^= ans[0];
						ans.erase(ans.begin()), ans.pb(num2);
						j ^= num2;
					}

				ans.pb(j | (1 << 17)), ans.pb(m | (1 << 17));

				cout << "YES" << endl;
				for(i = 0; i < ans.size(); i++) cout << ans[i] << " ";
			}
		return 0;
	}