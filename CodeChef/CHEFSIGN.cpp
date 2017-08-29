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
				int number = 0;
 
				cin >> s;
				n = s.size();
 
				for(i = 0; i < n; i++)
					{
						j = i;
						number = 1;

						while((s[j] == s[i] || s[j] == '=') && j < n)
							{
								if(s[j] != '=')
									number++;
								j++;
							}

						ans = max(ans, number);
						i = j-1;
					}

				cout << ans << endl;
			}
		return 0;
	} 

/*
><<<>>
*/