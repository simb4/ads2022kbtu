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


void heapify_down(int a[], int n, int v) {
    int best = v;
    if (2 * v <= n and a[2 * v] > a[best])
        best = 2 * v;
    if (2 * v + 1 <= n and a[2 * v + 1] > a[best])
        best = 2 * v + 1;
    if (v != best) {
        swap(a[v], a[best]);
        heapify_down(a, n, best);
    }
}

void heapify_up(int a[], int n, int v) {
    while (v != 1 && a[v/2] < a[v])
        swap(a[v/2], a[v]);
}

void push(int a[], int &n, int x) {
    n++;
    a[n] = x;
    heapify_up(a, n, n);
}

int get_max(int a[], int n) {
    return a[1];
}

int extract_max(int a[], int &n) {
    int mx = a[n];
    swap(a[1], a[n]);
    n--;
    heapify_down(a, n, 1);
    return mx;
}

void build(int a[], int n) {
    // for (int i = n / 2; i >= 1; i--)
    //     heapify_down(a, n, i);
    for (int i = 1; i <= n; i++) {
        heapify_up(a, n, i);    
    }
}

void heap_sort(int a[], int n) {
    build(a, n);
    int _n = n;
    for (int i = 1; i <= n; i++) {
        extract_max(a, _n);
    }
}

int main () {

    int n;
    cin >> n;
    int a[n];
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    heap_sort(a, n);
    for (int i = 1; i <= n; i++) {
        cout << a[i] << ' ';
    }
    cout << "\n";


    return 0;
}






