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

struct point
{
	int x, y;
};

point ans[1007];
int n=0;

int main()
	{
		int i;
		int ar1, ar2, ar3;
		int x41, x42, x43;
		int y41, y42, y43;
		int x1, y1, x2, y2, x3, y3;

		cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
		x41=x1+x2-x3;
		y41=y1+y2-y3;
		x42=x2+x3-x1;
		y42=y2+y3-y1;
		x43=x1+x3-x2;
		y43=y1+y3-y2;

		ar1=abs(x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2))+abs(x1*(y2-y41)+x2*(y41-y1)+x41*(y1-y2));
		ar2=abs(x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2))+abs(x42*(y2-y3)+x2*(y3-y42)+x3*(y42-y2));
		ar3=abs(x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2))+abs(x1*(y43-y3)+x43*(y3-y1)+x3*(y1-y43));

		if(ar1)
			{
				ans[n].x=x41;
				ans[n].y=y41;
				n++;
			}

		if(ar2)
			{
				ans[n].x=x42;
				ans[n].y=y42;
				n++;
			}

		if(ar3)
			{
				ans[n].x=x43;
				ans[n].y=y43;
				n++;
			}

		cout << n << endl;
		for(i=0; i<n; i++)
			cout << ans[i].x << " " << ans[i].y << endl;
		return 0;
	}