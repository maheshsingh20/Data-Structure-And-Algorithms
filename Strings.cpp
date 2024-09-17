#include <iostream>
#include <vector>
using namespace std;

int count(string allowed, vector<string> arr) {
    int cnt = 0;
    for (int i = 0; i < arr.size(); i++) {
        bool canForm = true;
        for (int j = 0; j < arr[i].size(); j++) {
            if (allowed.find(arr[i].at(j)) == string::npos) {
                canForm = false;
                break;
            }
        }
        if (canForm) {
            cnt++;
        }
    }
    return cnt;
}

int main() {
    string allowed = "ab";
    vector<string> arr = {"ad", "bd", "aaab", "baa", "badab"};
    int res = count(allowed, arr);
    cout << res << endl;
    return 0;
}