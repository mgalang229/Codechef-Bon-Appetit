#include <bits/stdc++.h>
 
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		int n, k;
		cin >> n >> k;
		map<int, vector<pair<int, int>>> mp;
		for (int i = 0; i < n; i++) {
			int arrival, departure, compartment;
			cin >> arrival >> departure >> compartment;
			mp[compartment].emplace_back(departure, arrival);
		}
		int cnt = 0;
		for (auto& x : mp) {
			if (x.second.empty()) {
				continue;
			}
			// if we sort this type of container, then it will compare the first value (departure)
			// however, if the first value is equal, then it will compare the second value (arrival)
			sort(x.second.begin(), x.second.end());
			int last = 0;
			for (pair<int, int> p : x.second) {
				// if the arrival value of the current customer is greater than or equal to the most recent
				// departure value of the previous customer, then we increment the counter and update the recent departure value
				if (p.second >= last) {
					cnt++;
					last = p.first;
				}
			}
		}
		cout << cnt << '\n';
 	}
	return 0;
}
