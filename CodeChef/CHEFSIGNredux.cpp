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
		int i, j, n, t;
		int left, right, equal, ans;
		string s;
 
		cin >> t;
 
		while(t--)
			{
				ans = 0;
				int number = 1;
 
				cin >> s;
				n = s.size();
 
				for(i = 0; i < n; i++)
					{
						if(s[i] == '<')
							number++;
						else if(s[i] == '>')
							number--;
						
						if(number == 0)
							{
								if(s[i] == '>')
									number = -2;
								else 
									number++;
							}
 
						ans = max(ans, abs(number));
					}
 
				// ans = max(left, right) - min(left, right);
				cout << ans << endl;
			}
		return 0;
	} 