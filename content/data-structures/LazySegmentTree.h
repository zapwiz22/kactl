/**
 * Author: Simon Lindholm
 * Date: 2016-10-08
 * License: CC0
 * Source: me
 * Description: Segment tree with ability to add or set values of large intervals, and compute max of intervals.
 * Can be changed to other things by modifying node, merge function and push function.
 * Time: O(\log N).
 * Usage: Node* tr = new Node(v, 0, sz(v));
 * Status: stress-tested a bit
 */
#pragma once

struct node {
	ll lazy;
	ll sum;
	node() {
		lazy = 0;
		sum = 0;
	}
};
node merge(node a, node b) {
	node ans;
	ans.sum = a.sum + b.sum;
	return ans;
}
node t[4 * 200200];
void push(int id, int l, int r) {
	if (t[id].lazy) {
		// if there is lazy then apply and push down 
		// apply logic.
		t[id].sum += 1ll * (r - l + 1) * t[id].lazy;
		// push down logic if not leaf.
		if (l != r) {
			t[id << 1 | 1].lazy += t[id].lazy;
			t[id << 1].lazy += t[id].lazy;
		}
		// clear.
		t[id].lazy = 0; 
	}
}
void build(int id, int l, int r) {
	if (l == r) {
		t[id].lazy = t[id].sum = 0;
		return;
	}
	int mid = l + (r - l) / 2;
	build(id << 1, l, mid);
	build(id << 1 | 1, mid + 1, r);
	t[id] = merge(t[id << 1], t[id << 1 | 1]); 
}
void update(int id, int l, int r, int lq, int rq, ll val) {
	push(id, l, r);
	if (lq > r || rq < l) return;
	if (lq <= l && rq >= r) { 
		t[id].lazy += val;
		push(id, l, r);
		return;
	}
	int mid = l + (r - l) / 2;
	update(id << 1, l, mid, lq, rq, val);
	update(id << 1 | 1, mid + 1, r, lq, rq, val);
	t[id] = merge(t[id << 1], t[id << 1 | 1]); 
}
node query(int id, int l, int r, int lq, int rq) {
	push(id, l, r);
	if (lq > r || rq < l) return node();
	if (lq <= l && rq >= r) return t[id];
	int mid = l + (r - l) / 2;
	return merge(query(id << 1, l, mid, lq, rq), query(id << 1 | 1, mid + 1, r, lq, rq));
}