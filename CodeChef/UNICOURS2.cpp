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
 
int a[100007];
int ans;
 
int main()
	{
		int t, n, i, maxv;
		vector<int>::iterator it;
 
		cin >> t;
 
		while(t--)
			{
				ans=-1;
 
				cin >> n;
 
				for(i=1; i<=n; i++)
					{
						cin >> a[i];
						ans=max(ans, a[i]);
					}

				cout << n-ans << endl;
			}

		return 0;
	} 