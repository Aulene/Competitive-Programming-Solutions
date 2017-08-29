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
 
#define lli long long
#define p push
#define pb push_back
#define mp make_pair

int main()
	{
		lli t, n, b, x, c, ans, m;
 
		cin >> t;
 
		while(t--)
			{
				cin >> n >> b;
				
				lli c = n / b;

				if(!(c % 2))
					{
						x = c / 2;
						m = n - (x * b);
						ans = m * x;
					}
				else
					{
						x = (c / 2) + 1;
						m = n - (x * b);
						ans = m * x;
					}

				cout << ans << endl;
			}
 
		return 0;
	} 