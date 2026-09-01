/**
 * Author: Jayant Kumar
 * Date: 2026-09-02
 * License: CC0
 * Source: me
 * Description: generation of random testcases for stress testing 
 * Status: none
 */
#pragma once

#include <bits/stdc++.h>
using namespace std;

#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main() {
	int tests = 1;
	cout << tests << endl;

	// generation 
	int n = uid(1, 1000);
	int x = uid(1, n);
	cout << n << " " << x << '\n';
}

/*
#!/bin/bash

g++ "$1"
g++ brute.cpp -o brute
g++ gen.cpp -o gen

for ((i = 1; i <= 1000; ++i)); do
    echo $i
    ./gen $i >int
    ./a.out <int >out1
    ./brute <int >out2
    diff -w out1 out2 || break
done
*/

/* how to generate a tree
  print uid(1,i-1) and i
*/

/* how to randomly shuffle a vector
   // Initialize random number generator
	random_device rd;
	mt19937 g(rd());

	// Shuffle the vector
	shuffle(v.begin(), v.end(), g);
*/