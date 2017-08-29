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

int dp[2007][2007];
stack <char> s;

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int i, j, n;
		string s1;
		char x;

		while(true)
			{
				int ans = 0, anshere = 0, left = 0, right = 0;

				cin >> s1;
				n = s1.size();

				for(i = 0; i < n; i++)
					{
						if(s1[i] == '{')
							{
								s.p('{');
								left++;
							}
						else
							{
								if(!s.empty())
									{
										if(s.top() == '{')
											{		
												s.pop();
												left--;
												right--;
											}
									}
								else
									s.p('}');
							}
					}

				ans = max(left, right) - min(left, right);
				cout << s.size() << endl;
				while(!s.empty())
					s.pop();

			}

		return 0;
	}