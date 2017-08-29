//Author : Ayush Jain
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <algorithm>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <set>
#include <list>
using namespace std;

#define ll long long
#define mod 1000000007

int main()
{
	ios_base::sync_with_stdio(false);
	ll foo[1000005],bar,*ptr,ans=0;
	int id1,id2;
	int i;
	for(i=0;i<1000005;i++) {
		foo[i]=(ll)i*(ll)i;
	}
	int a,b;
	cin>>a>>b;
	for(i=1;i<=a;i++){
		bar=(ll)i*(ll)i + 1;
		ptr=lower_bound(foo,foo+1000005,bar);
		id1=ptr-foo;
		if(!(foo[id1]>=bar)) continue;
		bar=(ll)i*(ll)i + b;
		ptr=lower_bound(foo,foo+1000005,bar);
		id2=ptr-foo;
		id2--;
		if(!(foo[id2]<=bar)) continue;
		ans+=(ll)(id2-id1+1);
	}
	cout<<ans<<endl;

	return 0;
}