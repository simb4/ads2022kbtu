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

struct node {
    int key;
    node *l = NULL; // left son
    node *r = NULL; // right son 
    node(){}
    node(int key) {
        this->key = key;
    }
};

node *root = NULL;

node* insert(node *v, int key) {
    if (v == NULL) {
        v = new node(key);
        return v;
    }
    if (key < v->key)
        v->l = insert(v->l, key);
    else
        v->r = insert(v->r, key);
    return v;
}

node* find(node *v, int key) {
    if (v == NULL)
        return NULL;
    if (v->key == key)
        return v;
    if (v->key < key)
        return find(v->l, key);
    return find(v->r, key);
}

bool del(node* root, int key) {
    // find the vertex
    node *par = NULL;
    node *cur = root;
    while (cur->key != key) {
        par = cur;
        if (cur->key < key)
            cur = cur->l;
        else
            cur = cur->r;
    }
    if (cur == NULL)
        return false;
    
    bool is_left_son = par != NULL && par->l != NULL && par->l->key == cur->key;
    bool is_right_son = par != NULL && par->r != NULL && par->r->key == cur->key;
    // our vertex is leaf
    if (cur->l == NULL && cur->r == NULL) {
        if (par != NULL) {
            // if its left child
            if (is_left_son)
                par->l = NULL;

            // if its right child
            if (is_right_son)
                par->r = NULL;
        }

        delete cur;
        return true;
    }

    // our vertex does not have right child
    if (cur->r == NULL) {

        if (par != NULL && is_left_son)
            par->l = cur->l;
        if (par != NULL && is_right_son)
            par->r = cur->l;

        delete cur;
        return true;
    }
    // our vertex does have right child:

    // TODO Compete it!

    return true;
}

void print(node* v, int tab = 0) {
    for (int i = 0; i < tab; i++)
        cout << "  ";
    if (v == NULL)
        cout << "NULL\n"; 
    else {
        cout << v->key << "\n";
        print(v->l, tab+1);
        print(v->r, tab+1);
    }
}

int main () {

    
    root = insert(root, 10);
    insert(root, 5);
    insert(root, 2);
    insert(root, 1);
    insert(root, 4);
    insert(root, 8);
    insert(root, 6);
    insert(root, 7);
    insert(root, 9);
    insert(root, 13);
    insert(root, 11);
    insert(root, 16);
    insert(root, 17);

    print(root);



    return 0;
}






