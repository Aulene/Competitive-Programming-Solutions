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
#include<fstream>

using namespace std;

#define lli long long int
#define mod 1000000007
#define pb push_back

int main()
	{
		ifstream fin ("square.in");
		ofstream fout ("square.out");
		
		int x1, y1, x2, y2;
		int x3, y3, x4, y4;

		fin >> x1 >> y1 >> x2 >> y2;
		fin >> x3 >> y3 >> x4 >> y4;

		int ans1, ans2, ans3, ans4, ans;

		ans1=min(y1, y3);
		ans2=max(y2, y4);
		ans3=min(x1, x3);
		ans4=max(x2, x4);

		ans1=abs(ans1-ans2);
		ans2=abs(ans3-ans4);

		ans=max(ans1, ans2);
		fout << ans*ans << endl;

		return 0;
	}