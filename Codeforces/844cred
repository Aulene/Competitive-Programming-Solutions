#include <iostream>
#include <algorithm>
using namespace std;
 
int m[100000], m1[100000], o[100000], p[100000];
 
int main() {
	int n, x = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> m[i];
		m1[i] = m[i];
	}
	sort(m1, m1 + n);
	for (int i = 0; i < n; i++) {
		if (p[i] == 0) {
			p[i] = 1;
			o[0] = i;
			x = 1;
			int pos = lower_bound(m1, m1 + n, m[o[x - 1]]) - m1;
			while (p[pos] != 1) {
				o[x] = pos;
				p[pos] = 1;
				x++;
				pos = lower_bound(m1, m1 + n, m[o[x - 1]]) - m1;
			}
			cout << x << ' ';
			for (int j = 0; j < x; j++) cout << o[j] + 1 << ' ';
			cout << '\n';
		}
	}
	system("pause");
}