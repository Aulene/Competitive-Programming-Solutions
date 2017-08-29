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
#define pb push_back

int main()
	{
		int n, m, i, j, cont;
		int maxA=0, maxB=0;
		int countA=0, countB=0;

		string s;

		cin >> n >> m >> s;

		for(i=0; i<n; i++)
			if(s[i]=='a')
				countA++;
			else
				countB++;

		for(i=0; i<n; i++)
			{
				j=i;
				cont=0;
				
				while(s[j]==s[i])
					{
						cont++;
						if(cont<=m)
							{
								if(s[i]=='a')
									maxB=max(j-i, maxB);
								else
									maxA=max(j-i, maxA);
							}
						j++;
					}

				i=j;
			}

		cout << maxA << " " << maxB << endl;

		int ans=max(maxA+countB, maxB+countA);
		cout << ans << endl;
		return 0;
	}