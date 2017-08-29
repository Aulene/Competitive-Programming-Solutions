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

map <char, lli> ans;
char x[5];

int main()
	{
		string s;
		int n, i, num=0;

		cin >> s;

		n=s.size();

		for(i=0; i<n; i++)
			{
				if(s[i]!='!')
					{
						x[num]=s[i];
					}

				num++;
				num=num%4;
			}

		num=0;
		for(i=0; i<n; i++)
			{
				if(s[i]=='!')
					{
						ans[x[num]]++;
					}

				num=(num+1)%4;
			}

		cout << ans['R'] << " " << ans['B'] << " " << ans['Y'] << " " << ans['G'] << endl;
		return 0;
	}