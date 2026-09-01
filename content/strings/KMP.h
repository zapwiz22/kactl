/**
 * Author: Johan Sannemo
 * Date: 2016-12-15
 * License: CC0
 * Description: pi[x] computes the length of the longest prefix of s that ends at x,
 * other than s[0...x] itself (abacaba -> 0010123).
 * Can be used to find all occurrences of a string.
 * Time: O(n)
 * Status: Tested on kattis:stringmatching
 */
#pragma once

vector<int> kmp(vector<int>& pat) {
	int n = (int)pat.size();
	// lps[i] => longest prefix which is also suffix for the sub-pattern [0...i]
	vector<int> lps(n, 0);
	int i = 1, len = 0;
	while (i < n) {
		if (pat[i] == pat[len]) {
			len++, lps[i] = len, i++;
		} else {
			if (len != 0) len = lps[len - 1];
			else i++;
		}
	}
}