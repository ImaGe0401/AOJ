//include
//------------------------------------------
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <bits/stdc++.h>
#include<queue>
#include <numeric>
using namespace std;
 
//conversion
//------------------------------------------
inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}
 
//math
//-------------------------------------------
template<class T> inline T sqr(T x) {return x*x;}
 template<class T>bool chmin(T &a, const T &b) { if (b<a) { a = b; return 1; } return 0; }
//typedef
//------------------------------------------
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef long long LL;
 
//container util
//------------------------------------------
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define MP make_pair
#define SZ(a) int((a).size())
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())
 
//repetition
//------------------------------------------
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define fore(i,a) for(auto &i:a)

//constant
//--------------------------------------------
const double EPS = 1e-10;
const double PI  = acos(-1.0);
 
//clear memory
#define CLR(a) memset((a), 0 ,sizeof(a))
 
//debug
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;


struct Node{
    int key;
    Node *right, *left, *parent;
};

Node *root, *NIL;

Node * treeMinimum(Node *x){
    while(x->left != NIL)
        x = x->left;
    return x;
}

Node * find(Node *u, int k){
    while(u!=NIL && k != u->key){
        if(k < u->key)
            u = u->left;
        else
            u = u->right;
    }
    return u;
}

Node * treeSuccessor(Node *x){
    if(x->right != NIL)
        return treeMinimum(x->right);
    Node *y = x->parent;
    while(y!= NIL && x==y->right){
        x = y;
        y = y->parent;
    }
    return y;
}

void treeDelete(Node *z){
    Node *y;
    Node *x;

    if(z->left == NIL || z->right == NIL)
        y = z;
    else
        y = treeSuccessor(z);
    if(y->left != NIL){
        x = y->left;
    }else{
        x = y->right;
    }

    if(x != NIL){
        x->parent = y->parent;
    }

    if(y->parent == NIL){
        root = x;
    }else{
        if(y == y->parent->left){
            y->parent->left = x;
        }else{
            y->parent->right = x;
        }
    }
    if(y!=z){
        z->key = y->key;
    }

    free(y);
}

void insert(int k){
    Node *y = NIL;
    Node *x = root;
    Node *z;

    z = (Node *)malloc(sizeof(Node));
    z->key = k;
    z->left = NIL;
    z->right = NIL;
    
    while(x != NIL){
        y = x;
        if(z->key < x-> key){
            x = x->left;
        }else{
            x = x->right;
        }
    }
    z->parent = y;
    if(y == NIL){
        root = z;
    }else{
        if(z->key < y->key){
            y->left = z;
        }else{
            y->right = z;
        }
    }
}

void inorder(Node *u){
    if(u==NIL)
        return;
    inorder(u->left);
    printf(" %d", u->key);
    inorder(u->right);
}

void preorder(Node *u){
    if(u==NIL)
        return;
    printf(" %d", u->key);
    preorder(u->left);
    preorder(u->right);
}

int main(){
    int n, i, x;
    string com;

    scanf("%d", &n);

    for (i = 0; i < n; ++i){
        cin >> com;
        if(com[0] == 'f'){
            scanf("%d", &x);
            Node *t = find(root, x);
            if(t!= NIL)
                printf("yes\n");
            else
                printf("no\n");
        }else if(com == "insert"){
            scanf("%d", &x);
            insert(x);
        }
        else if (com == "print")
        {
            inorder(root);
            printf("\n");
            preorder(root);
            printf("\n");
        }else if(com == "delete"){
            scanf("%d", &x);
            treeDelete(find(root, x));
        }
    }
    return 0;
}