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

stack<string> a;
stack<string> ans;

int main()
	{
		int n, i;
		int len, prev;

		string s, s1, newS;

		cin >> n;

		while(n--)
			{
				cin.getline(s, 80);

				newS="";
				len=s.size();
				prev=0;

				for(i=0; i<len; i++)
					if(s[i]==' ')
						{
							s1=s.substr(prev, i-prev);
							//cout << prev << " " << i << endl;
							//cout << s1 << endl;
							a.push(s1);
							prev=i+1;
						}

				s1=s.substr(prev, len-prev);
				a.push(s1);

				while(!a.empty())
					{
						s1=a.top();
						a.pop();

						len=s1.size();

						if(!((s1[len-1]>='A' && s1[len-1]<='Z') || (s1[len-1]>='a' && s1[len-1]<='z')))
							s1[len-1]=' ';
						s1+=" ";
						newS+=s1;
					}

				cout << newS << endl;
				ans.push(newS);

				if(n==0)
					break;
			}

		while(!ans.empty())
			{
				cout << ans.top() << endl;
				ans.pop();
			}
		return 0;
	}

