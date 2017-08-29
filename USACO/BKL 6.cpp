#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define p push_back

vector<string> a;

int recur(string s) {
	int n = s.size();	
	if (s.size() == 0)
		return 1;
	vector<string>::iterator it;
	string st, st2;
	int ans=0;
	for(int i=1; i <= min(n, 3); i++) {
		st=s.substr(0, i);
		for(it=a.begin(); it!=a.end(); it++) {
				string u = *it;
				if (st == u) {
					st2 = s.substr(i, s.size() - i);
					ans = max(ans, recur(st2));
				}
		}
	}
	return ans;
}

int main() {
	a.p("sin");
	a.p("si");
	a.p("s");
	a.p("cos");
	a.p("co");
	a.p("c");
	a.p("tan");
	a.p("ta");
	a.p("t");
	a.p("log");
	a.p("lo");
	a.p("l");
	a.p("e");
	string s;
	cin >> s;
	int ans;
	ans = recur(s);
	cout << ans << endl;
	return 0;
}