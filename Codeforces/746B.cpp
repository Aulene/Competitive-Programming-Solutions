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
		int n, i, pos1=0, pos2, x=0;
		string s;
		bool f=0;

		cin >> n >> s;

		string ans(s.size(), '0');
		pos2=ans.size();

		if(s.size()%2)
			{
				pos2=(n-1)/2;
				pos1=(n-1)/2-1;
				f=0;
			}
		else
			{
				pos2=(n-1)/2+1;
				pos1=(n-1)/2;
				f=1;
			}

		while(pos1>=0 || pos2<n)
			{
				if(!f)
					{
						ans[pos2]=s[x];
						pos2++;
						f=1;
					}
				else
					{
						ans[pos1]=s[x];
						pos1--;
						f=0;
					}

				x++;
			}

		cout << ans << endl;
		return 0;
	}