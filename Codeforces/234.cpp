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
const int N=123456;
int n,m,i,res,k,p,tr;
vector <int> v;
int main()
{
	scanf("%d%d",&n,&m);
	if(n==1){
		puts("YES\n");
		printf("%d",m);
		return 0;
	}
	if(n==2 && !m){
		puts("NO");
	}
	else{
		k=n,p=0,res=0;
		while(k-- >2){
			tr^=p;
			v.push_back(p++);
		}
		if(tr==m){
			tr^=v[0];
			v.erase(v.begin());
			v.push_back(p);
			tr^=p;
		}
		v.push_back(tr | (1<<17));
		v.push_back(m | (1<<17));
		puts("YES\n");
		for(int i : v){
			cout<<i<<" ";
		}
	}
    return 0;
}
