/**
 * Author: Lucian Bicsi
 * Date: 2017-10-31
 * License: CC0
 * Source: folklore
 * Description: Zero-indexed max-tree. Bounds are inclusive.
 * Can be changed by modifying node and merge function. 
 * See the 't' size.
 * Time: O(\log N)
 * Status: stress-tested
 */
#pragma once

struct node {
	ll sum = 0;
	node() {
		sum = 0;
	}
};
node merge(node a, node b) {
	node ans;
	ans.sum = max(a.sum, b.sum);
	return ans;
}
node t[4 * 200200];
void build(int id, int l, int r) {
	if (l == r) {
		t[id].sum = 0;
		return;
	}
	int mid = l + (r - l) / 2;
	build(id * 2, l, mid);
	build(id * 2 + 1, mid + 1, r);
	t[id] = merge(t[id * 2], t[id * 2 + 1]);
}
void update(int id, int l, int r, int pos, ll u) {
	if (l > pos || r < pos) return;
	if (l == r) {
		t[id].sum = u;
		return;
	}
	int mid = l + (r - l) / 2;
	update(id * 2, l, mid, pos, u);
	update(id * 2 + 1, mid + 1, r, pos, u);
	t[id] = merge(t[id * 2], t[id * 2 + 1]);
}
node query(int id, int l, int r, int lq, int rq) {
	if (l >= lq && r <= rq) return t[id];
	if (lq > r || rq < l) return node();
	int mid = l + (r - l) / 2;
	return merge(query(id * 2, l, mid, lq, rq), query(id * 2 + 1, mid + 1, r, lq, rq));
}
