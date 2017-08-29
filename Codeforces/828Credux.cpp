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
#define ll long long
#define ull unsigned long long int
using namespace std;
#define clr(v , d)	memset(v , d , sizeof v)
#define sz(v)		((int)(v).size())
const int VISITED = 1;
const int UNVISITED = -1;
const long long OO = 1e12;
const int OOI = 1e9;
#define f first
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int xdir[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int ydir[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

string o = string(1000000+9,'a');
int mxind = 0;
void change (string s , int ind){
	for(int i = 0 ; i < sz(s) ;i++){
		if(o[ind] != s[i]){
			o[ind] = s[i];
		}
		ind++;
		if(mxind < ind)
			mxind=ind;
	}	
}

int main() {
	int n   , x , k;
	cin >> n ;
	for(int i = 0 ; i < n ; i++){
		string s ;
		cin >> s ;
		cin >> k ;
		for(int j = 0 ; j < k ; j++	){
			cin >> x;
			change(s , x);
		}
	}
	for(int i = 1 ; i < mxind; i++)
		cout<<o[i];
	cout<<endl;
	return 0;
}

