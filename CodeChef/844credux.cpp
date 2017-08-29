#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
struct data {
    int x, y;
};
 
bool dataSort(data a, data b) {
    return (a.x < b.x || (a.x == b.x && a.y < b.y));
}
 
int main() {
    int n;
    cin >> n;
    vector<data> a(n);
    std::vector< std::vector<int> > ans;
    int count = 0, working = 0;
    for (int i=0; i<n; i++) {
        cin >> a[i].x;
        a[i].y = i;
    }
    vector<data> tmp(a);
    sort(tmp.begin(), tmp.end(), dataSort);
    for (int i=0; i<n; i++) {
        a[tmp[i].y].y = i;
    }

    for(int i = 0; i < n; i++)
        cout << a[i].y << " ";

    for (int i=0; i<n; i++) {
        if (a[i].y > i) {
            count++; working = count-1;
            vector<int> tmpV;
            ans.push_back(tmpV);
            ans[working].push_back(i+1);
        }
        else if (a[i].y == i) {
            vector<int> tmpV(1); tmpV[0] = i+1;
            ans.push_back(tmpV); count++;
        }
        else {
            ans[working].push_back(i+1);
        }
    }
    cout << count << endl;
    for (int i=0; i<ans.size(); i++) {
        cout << ans[i].size();
        for (int j=0; j<ans[i].size(); j++) cout << " " << ans[i][j];
        cout << endl;
    }
	return 0;
}