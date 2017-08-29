#include<iostream>
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
#define pb push_back

int main()
	{
		int t, n, i, ans=0;
		string s;

		cin >> t;

		while(t--)
			{
				cin >> s;
				n=s.size();

				for(i=0; i<n; i++)
					if(s[i]=='A')
						ans+=4;
					else if(s[i]=='K')
						ans+=3;
					else if(s[i]=='Q')
						ans+=2;
					else if(s[i]=='J')
						ans++;
			}

		cout << ans << endl;
		return 0;
	}