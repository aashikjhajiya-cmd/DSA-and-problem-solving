#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
    int n, target;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cin >> target;

    unordered_map<int, int> mp;

    for (int i = 0; i < n; i++) {
        int required = target - arr[i];

        if (mp.find(required) != mp.end()) {
            cout << mp[required] << " " << i;
            return 0;
        }

        mp[arr[i]] = i;
    }

    cout << "-1 -1";

    return 0;
}
