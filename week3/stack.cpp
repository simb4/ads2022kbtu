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

const int MAXN = (int)1e5;

struct Stack {
  int n; // size of stack
  int a[MAXN]; // [0, n-1] - positions for stack
  // [1,2,3,4] - init stack
  // push 5
  // [1,2,3,4,5]
  // push 1
  // [1,2,3,4,5,1]
  // pop
  // pop
  // [1,2,3,4] 
  // top => 4

  Stack() {
    n = 0;
  }

  int size() {
    return n;
  }

  int top() {
    if (n == 0) {
      cout << "Error: stack is empty!\n";
      exit(0);
    }
    return a[n-1];
  }

  void push(int x) {
    a[n] = x;
    n++;
  }

  void pop() {
    if (n == 0) {
      cout << "Error: stack is empty!\n";
      exit(0);
    }
    n--;
  }
};

int main () {
  int tests;
  cin >> tests;
  Stack st;
  for (int i = 0; i < tests; i++) {
    string s;
    cin >> s;
    if (s == "size") {
      cout << st.size() << "\n";
    }
    else if (s == "pop") {

      st.pop();
      cout << "OK\n";

    } else if (s == "top") {

      cout << st.top() << "\n";

    } else if (s == "push") {

      int x;
      cin >> x;
      st.push(x);
      cout << "OK\n";

    }
  }



  return 0;
}






