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
		string s;
		int n, i, start, end;
		bool ans, type2;
		char prev;

		while(cin >> s)
			{
				ans=1;

				if(s=="X")
					break;

				n=s.size();
				start=0, end=n-1;
				prev=s[0];

				while(s[start]=='B')
					start++;
				while(s[end]=='S')
					end--;

				//cout << start << endl << end << endl;
				prev=s[start];
				for(i=start+1; i<=end; i++)
					{
						if((s[i]=='A' && prev=='N') || (s[i]=='N' && prev=='A'))
							{
								prev=s[i];
								continue;
							}	
						else
							{
								ans=0;
								break;
							}
					}

				if((start>0 && end==n-1) || (start==0 && end<n-1) )
					ans=0;
				//cout << type2 << endl;
				if(ans)
					cout << "YES" << endl;
				else
					cout << "NO" << endl;
			}

		return 0;
	}