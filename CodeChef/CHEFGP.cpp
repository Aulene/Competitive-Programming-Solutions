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

vector <char> ans;

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int t, n, x, y, a, b, i, j, x1, y1;
		string s;

		cin >> t;

		while(t--)
			{
				ans.clear();

				cin >> s >> x >> y;
				n = s.size();

				a = b = x1 = y1 = 0;

				for(i = 0; i < n; i++) if(s[i] == 'a') a++; else b++;

				for(i = 0; i < n; i++)
					{
						if(a > b)
							{
								if(x1 == x)
									{
										if(b)
											{
												ans.pb('b');
												b--;
												x1 = 0; y1 = 1;
											}
										else
											{
												ans.pb('*'); ans.pb('a');
												a--;
												x1 = 1; y1 = 0;
											}
									}
								else
									{
										ans.pb('a');
										a--;
										x1++; y1 = 0;
									}
							}
						else
							{
								if(y1 == y)
									{
										if(a)
											{
												ans.pb('a');
												a--;
												x1++; y1 = 0;
											}
										else
											{
												ans.pb('*'); ans.pb('b');
												b--; 
												x1 = 0; y1 = 1;
											}
									}
								else
									{
										ans.pb('b');
										b--;
										x1 = 0; y1++;
									}
							}
					}

				for(i = 0; i < ans.size(); i++) cout << ans[i]; cout << endl;
			}
		
		return 0;
	}