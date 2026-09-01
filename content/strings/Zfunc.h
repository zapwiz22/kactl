/**
 * Author: chilli
 * License: CC0
 * Description: z[i] computes the length of the longest common prefix of s[i:] and s,
 * except z[0] = 0. (abacaba -> 0010301)
 * Time: O(n)
 * Status: stress-tested
 */
#pragma once

vector<int> z_func(string s) {
	int n = s.size();
	vector<int> z(n);
	int l = 0, r = 0;
	for (int i = 0; i < n; i++) {
		z[i] = max(0, min(z[i - l], r - i + 1));
		while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
			l = i, r = i + z[i], z[i]++;
		}
	}
	return z;
}
