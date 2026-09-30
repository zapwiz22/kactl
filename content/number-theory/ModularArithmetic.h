/**
 * Author: Lukas Polacek, Joshua Andersson
 * Date: 2009-09-28
 * License: CC0
 * Source: folklore
 * Description: Operators for modular arithmetic. You need to set {\tt mod} to
 * some number first and then you can use the structure.
 */
#pragma once

const ll mod = 1e9 + 7;
template<int mod>
struct Mint {
	ll x;
	Mint(ll y = 0) : x((y % mod + mod) % mod){}
	Mint operator+(Mint b) { return {x + b.x}; }
	Mint operator-(Mint b) { return {x - b.x}; }
	Mint operator*(Mint b) { return {x * b.x}; }
	Mint operator/(Mint b) { return *this * inv(b); }
	Mint inv(Mint a) { return a ^ (mod - 2); }
	Mint operator^(ll e) {
		if (!e) return 1;
		Mint r = *this ^ (e / 2); r = r * r;
		return e&1 ? *this * r : r;
	}
};
using mint = Mint<mod>;