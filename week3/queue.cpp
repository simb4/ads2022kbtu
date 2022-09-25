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

struct Queue {
  int head, tail; 
  int a[MAXN]; 
  // invariant: a[head, tail)
  // invariant: head <= tail
  /*
  [] , head = tail = 0
  push 1
  [1], head = 0, tail = 1
  push 2
  [1,2] head = 0, tail = 2
  pop
   1[2] head = 1, tail = 2
  */
  int front() {
    if (head == tail) {
      cout << "Error: queue is empty!\n";
      exit(0);
    }
    return a[head];
  }

  int back() {
    if (head == tail) {
      cout << "Error: queue is empty!\n";
      exit(0);
    }
    return a[tail - 1];
  }

  int size() {
    return tail - head;
  }
  
  void push(int x) { 
    a[tail] = x;
    tail++;
  }

  void pop() {
    if (head == tail) {
      cout << "Error: queue is empty!\n";
      exit(0);
    }
    head++;
  }

};

int main () {
  
  int tests;
  cin >> tests;

  Queue q;

  for (int i = 0; i < tests; i++) {
    string s;
    cin >> s;
    if (s == "pop") {

      q.pop();
      cout << "OK\n";

    }
    else if (s == "front") {

      cout << q.front() << "\n";

    }
    else if (s == "back") {

      cout << q.back() << "\n";

    }
    else if (s == "push") {
      int x;
      cin >> x;
      q.push(x);
      cout << "OK\n";
    }
    else if (s == "size") {
      cout << q.size() << "\n";
    }

  }



  return 0;
}






