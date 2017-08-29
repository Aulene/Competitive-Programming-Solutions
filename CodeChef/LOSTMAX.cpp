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
#include <sstream>
#include <string>
#include <utility>
#include <iterator>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

stack<int> v;

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int t, i, j, ans;
		bool foundN;
		string s;

		cin >> t;
		cin.ignore();

		while(t--)
			{
				int n;
				ans = 0;
				foundN = 0;	
				
				getline(cin, s);
				istringstream is(s);

				while(is >> n)
					{
						v.p(n);
					}

				n = v.size();

				while(!v.empty())
					{
						j = v.top();
						if(j == n - 1 && foundN == 0)
							foundN = 1;
						else if(j > ans)
							ans = j;
						v.pop();
					}
				cout << ans << endl;
			}	

		return 0;
	}