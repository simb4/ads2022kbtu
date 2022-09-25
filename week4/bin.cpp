#include <iostream>
#include <bits/stdc++.h>
#include <cmath>
#include <algorithm>
#include <vector>
#include <deque>
#include <set>
#include <stack>
#include <string>
#include <map>
#include <queue>

using namespace std;

const int N = (int)1e5;

int n; // number of farms 
int x[N]; // coordinates of farms
int k; // number of cows

bool check(int d) {
  int cnt = 0; // counter for cows
  int last = -(int)1e9; // coordinate of last farm that have a cow
  for (int i = 1; i <= n; i++) {
    if (x[i] - last >= d) { // put the cow at i
      cnt++;
      last = x[i];
    }
  }
  return cnt >= k;
}

int main () {
  
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> x[i];
  }
  int l = 1; // f(l) = true
  int r = 1e9 + 5; // f(r) = false
  while (r - l > 1) {
    int m = (l + r) / 2;
    if (check(m)) {
      l = m;
    } else {
      r = m;
    }
  }
  // [l, l + 1]
  cout << l << "\n";




  return 0;
}






